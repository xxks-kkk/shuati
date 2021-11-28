import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;

// LC-1152
public class AnalyzeUserWebsiteVisitPattern
{
    public List<String> mostVisitedPattern(String[] username, int[] timestamp, String[] website)
    {
        Map<String, List<Pair>> map = new HashMap<>();
        int n = username.length;
        // collect the website info for every user, key: username, value: (timestamp, website)
        for (int i = 0; i < n; i++) {
            map.putIfAbsent(username[i], new ArrayList<>());
            map.get(username[i]).add(new Pair(timestamp[i], website[i]));
        }
        // count map to record every 3 combination occurring time for the different user.
        Map<String, Integer> count = new HashMap<>();
        String res = "";
        for (String key : map.keySet()) {
            // this set is to avoid visit the same 3-seq in one user
            Set<String> set = new HashSet<>();
            List<Pair> list = map.get(key);
            // sort by time (this avoids sort timestamp and then sort username, website following timestamp)
            list.sort(Comparator.comparingInt(a -> a.time));
            // brutal force O(N ^ 3)
            for (int i = 0; i < list.size(); i++) {
                for (int j = i + 1; j < list.size(); j++) {
                    for (int k = j + 1; k < list.size(); k++) {
                        String str = list.get(i).web + " " + list.get(j).web + " " + list.get(k).web;
                        if (!set.contains(str)) {
                            count.put(str, count.getOrDefault(str, 0) + 1);
                            set.add(str);
                        }
                        if (res.equals("") ||
                                count.get(res) < count.get(str) ||
                                (Objects.equals(count.get(res), count.get(str)) && res.compareTo(str) > 0) /* make sure the right lexi order */) {
                            res = str;
                        }
                    }
                }
            }
        }
        // grab the right answer
        String[] r = res.split(" ");
        List<String> result = new ArrayList<>();
        Collections.addAll(result, r);
        return result;
    }

    static class Pair
    {
        int time;
        String web;

        public Pair(int time, String web)
        {
            this.time = time;
            this.web = web;
        }
    }
}
