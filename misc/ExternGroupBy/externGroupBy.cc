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
    // The number of temp files we want to use
    // This number should not be greater than the queue_size_limit
    unsigned long numFiles = 2;
    int runNum = 0;
    bool startRun = true;

    typedef std::function<bool(std::pair<std::string, std::string>, std::pair<std::string, std::string>)> Comparator;
    Comparator comp = [](std::pair<std::string, std::string> item1, std::pair<std::string, std::string> item2) -> bool
    {
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
                outfile.open("run" + std::to_string(runNum % numFiles), std::ios_base::app);
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
                    // marker to separate runs within a file
                    outfile << std::endl;
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
    // It's possible that our priority_queue is large and there are still some pairs left in the queue
    // The elements inside the queue belong to the run we haven't finished in the loop.
    while (!pq.empty())
    {
        auto target = pq.top();
        outfile << target.first << " " << target.second << std::endl;
        pq.pop();
    }
    outfile << std::endl;
    runNum++;
    outfile.close();

    // The leftout elements in buffer belongs to a new run
    if (!outfile.is_open())
    {
        outfile.open("run" + std::to_string(runNum % numFiles), std::ios_base::app);
    }
    while (buffer.size() > 0)
    {
        auto item = buffer.front();
        pq.push(item);
        buffer.pop();
    }
    while (!pq.empty())
    {
        auto target = pq.top();
        outfile << target.first << " " << target.second << std::endl;
        pq.pop();
    }
    outfile << std::endl;
    runNum++;
    outfile.close();

    // Now, we merge the result
    // We first create another file for polyphase merge
    outfile.open("run" + std::to_string(numFiles), std::ios_base::app);
    outfile.close();
    // A bitmap to keep track of which files are empty (ie. 0)
    std::vector<int> emptyFile(numFiles + 1, 1);
    // Keep track of which file to use next
    int FileToUseNext = numFiles;
    // The newly created one is empty
    emptyFile[FileToUseNext] = 0;
    // Keep track of which part of the file we should begin to read
    std::vector<long int> fileStart(numFiles + 1);
    // Keep track of runs we have process so far. We reset when all the ith run of each
    // file has been processed
    int numRuns = 0;

    // <key,value, filename, read position from last time>
    typedef std::function<bool(std::tuple<std::string, std::string, int, long int>,
                               std::tuple<std::string, std::string, int, long int>)>
        Comparator2;
    Comparator2 comp2 =
        [](std::tuple<std::string, std::string, int, long int> item1,
           std::tuple<std::string, std::string, int, long int> item2) -> bool
        {
            return std::get<0>(item1) > std::get<0>(item2);
        };
    // define a min heap
    std::priority_queue<std::tuple<std::string, std::string, int, long int>,
                        std::vector<std::tuple<std::string, std::string, int, long int>>,
                        Comparator2> pq2(comp2);

    std::ifstream infile;

    while (std::accumulate(emptyFile.begin(), emptyFile.end(), 0) != 1)
    {

        for (int i = 0; i < emptyFile.size(); ++i)
        {
            if (emptyFile[i] == 1)
            {
                infile.open("run" + std::to_string(i));
                infile.seekg(fileStart[i]);
                long int pos;
                for (std::string line; std::getline(infile, line);)
                {
                    pos = infile.tellg();
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
                        pq2.push(std::tuple<std::string, std::string, int, long int>{key, val, i, pos});
                        break;
                    }
                }
                fileStart[i] = pos;
                infile.close();
            }
        }

        outfile.open("run" + std::to_string(FileToUseNext));
        emptyFile[FileToUseNext] = 1;
        while (!pq2.empty())
        {
            auto item = pq2.top();
            outfile << std::get<0>(item) << " " << std::get<1>(item) << std::endl;
            pq2.pop();
            infile.open("run" + std::to_string(std::get<2>(item)));
            infile.seekg(std::get<3>(item));
            std::string line;
            std::getline(infile, line);
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
                pq2.push(std::tuple<std::string, std::string, int, long int>{key, val, std::get<2>(item),
                                                                             infile.tellg()});
            }
            else
            {
                // we read empty line, which means we have finished processing a run
                numRuns++;
                if (numRuns == numFiles)
                {
                    // All the ith run of each file has been processed. We can insert a blank line to the end
                    outfile << std::endl;
                    numRuns = 0;
                }
            }
            fileStart[std::get<2>(item)] = infile.tellg();
            std::string tmp;
            // Check whether we have reached the EOF
            while (!getline(infile, tmp))
            {
                FileToUseNext = std::get<2>(item);
                emptyFile[FileToUseNext] = 0;
                std::ofstream infile2;
                infile2.open("run" + std::to_string(FileToUseNext));
                infile2.close();
                fileStart[FileToUseNext] = 0;
                break;
            }
            infile.close();
        }
        outfile.close();
    }

    // By here, all the key values records are conslidated into one file with the key in the sorted order
    // Now we can merge the same keys and output the result to the stdout

}
}