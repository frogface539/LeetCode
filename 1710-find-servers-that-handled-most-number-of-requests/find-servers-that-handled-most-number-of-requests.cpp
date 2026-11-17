class Solution {
public:
    typedef pair<int, int> P; //{finishTime, serverId}

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i = 0; i < k; i++) {
            available_servers.insert(i); //k * log(k)
        }

        priority_queue<P, vector<P>, greater<P>> busyServers;

        vector<int> countRequests(k, 0);

        for(int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];

            while(!busyServers.empty() && busyServers.top().first <= time) {
                int server = busyServers.top().second;

                busyServers.pop();

                available_servers.insert(server);
            }

            int target = i%k;

            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()) { //wrap around
                it = available_servers.begin();
            }

            if(available_servers.empty()) {
                continue; //no servers available. Drop the current request
            }

            int targetServer = *it;

            available_servers.erase(it); 

            busyServers.push({time + load[i], targetServer});

            countRequests[targetServer]++;

        }

        int maxNumberOfRequests = *max_element(begin(countRequests), end(countRequests)); 

        vector<int> result;

        for(int i = 0; i < k; i++) {
            if(countRequests[i] == maxNumberOfRequests) {
                result.push_back(i);
            }
        }

        return result;
    }
};