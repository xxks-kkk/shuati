/*************************************************************************
  > File Name:       externGroupBy.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/19/18
  > Description:
    
    The actual implementation of externGroupBy
 ************************************************************************/

#include "externGroupBy.h"
#include "utility.h"

namespace ExternGroupBy
{
/**
 * The baseline for External GroupBy. The implementation is exactly the same as brute_force.py.
 */
void
externGroupByBaseline()
{
    int memoryLimit;
    std::cin >> memoryLimit;
    std::map<std::string, std::vector<std::string>> key_dict;
    for (std::string line; std::getline(std::cin, line);)
    {
        std::stringstream ss(line);
        std::string buf;
        std::vector<std::string> tokens;
        while (ss >> buf)
        {
            tokens.emplace_back(buf);
        }
        if (!tokens.empty())
        {
            auto key = tokens[0];
            auto val = tokens[1];
            if (key_dict.find(key) == key_dict.end())
            {
                key_dict[key] = {val};
            }
            else
            {
                key_dict[key].emplace_back(val);
            }
        }
    }
    for (auto &item : key_dict)
    {
        std::sort(item.second.begin(), item.second.end());
        std::cout << item.first << " " << Utility::join(item.second, " ") << std::endl;
    }
}

/**
 * Our actual implementation
 */
void
externGroupBy()
{
    unsigned int memoryLimit;
    std::cin >> memoryLimit;
    // A knob to determine whether we should estimate the queue size limit
    bool estimate = true;
    unsigned long queue_size_limit;
    int runNum = 0;
    bool startRun = true;
    typedef std::function<bool(std::pair<std::string,std::string>, std::pair<std::string,std::string>)> Comparator;
    Comparator comp = [](std::pair<std::string,std::string> item1, std::pair<std::string,std::string> item2) -> bool{
        return item1.first > item2.first;
    };
    // define a min heap
    std::priority_queue<std::pair<std::string, std::string>,
                        std::vector<std::pair<std::string, std::string>>,
                        Comparator> pq(comp);
    std::queue<std::pair<std::string, std::string>> buffer;
    std::ofstream outfile;
    // We first build runs
    for (std::string line; std::getline(std::cin, line);)
    {
        std::stringstream ss(line);
        std::string buf;
        std::vector<std::string> tokens;
        while (ss >> buf)
        {
            tokens.emplace_back(buf);
        }
        if (!tokens.empty())
        {
            auto key = tokens[0];
            auto val = tokens[1];
            if (estimate)
            {
                // We estimate the size of priority queue we want to use
                queue_size_limit = memoryLimit / (key.length() + val.length() + 2);
                estimate = false;
            }
            if (!outfile.is_open())
            {
                outfile.open("run" + std::to_string(runNum));
            }
            if (startRun)
            {
                if (pq.size() < queue_size_limit)
                {
                    pq.push(std::pair<std::string, std::string>{key, val});
                }
                if (pq.size() == queue_size_limit)
                {
                    startRun = false;
                }
            }
            else
            {
                if (!pq.empty())
                {
                    auto target = pq.top();
                    outfile << target.first << " " << target.second << std::endl;
                    pq.pop();
                    if (target.first.compare(key) < 0)
                    {
                        pq.push(std::pair<std::string, std::string>{key, val});
                    }
                    else
                    {
                        buffer.push(std::pair<std::string, std::string>{key, val});
                    }
                }
                if (pq.empty())
                {
                    outfile.close();
                    runNum++;
                    if (buffer.size() < queue_size_limit)
                    {
                        startRun = true;
                    }
                    while (buffer.size() > 0)
                    {
                        auto item = buffer.front();
                        pq.push(item);
                        buffer.pop();
                    }
                }
            }
        }
    }
    if (!outfile.is_open())
    {
        outfile.open("run" + std::to_string(runNum));
    }
    while(buffer.size() > 0)
    {
        auto item = buffer.front();
        pq.push(item);
        buffer.pop();
    }
    // It's possible that our priority_queue is large and there are still some pairs left in the queue
    while (!pq.empty())
    {
        auto target = pq.top();
        outfile << target.first << " " << target.second << std::endl;
        pq.pop();
    }
    outfile.close();
}
}