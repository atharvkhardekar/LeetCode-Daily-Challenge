// LeetCode Problem No. 3508
// Daily Challenge - 20/09/2025

class Router{
    using ll = long long;
    int size_;
    unordered_map<ll, array<int, 3>> packets;
    unordered_map<int, vector<int>> cnt;
    queue<ll> q;

    static ll encode(int s, int d, int t)
    {
        return (((ll)s << 40) | ((ll)d << 20) | (ll)t);
    }

public:
    Router(int memoryLimit)
    {
        size_ = memoryLimit;
        packets.reserve(max(1, memoryLimit * 2));
    }
    bool addPacket(int source, int destination, int timestamp)
    {
        ll key = encode(source, destination, timestamp);
        if (packets.count(key))
            return false;
        if ((int)packets.size() >= size_)
        {
            forwardPacket();
        }
        packets[key] = {source, destination, timestamp};
        q.push(key);

        auto &v = cnt[destination];
        auto it = lower_bound(v.begin(), v.end(), timestamp);
        v.insert(it, timestamp);
        return true;
    }
    vector<int> forwardPacket()
    {
        if (packets.empty())
            return {};
        ll key = q.front();
        q.pop();
        auto it = packets.find(key);
        if (it == packets.end())
            return {};
        auto packet = it->second;
        packets.erase(it);
        int d = packet[1];
        int ts = packet[2];
        auto &v = cnt[d];
        auto itv = lower_bound(v.begin(), v.end(), ts);
        if (itv != v.end() && *itv == ts)
            v.erase(itv);
        return {packet[0], packet[1], packet[2]};
    }
    int getCount(int destination, int startTime, int endTime)
    {
        auto it = cnt.find(destination);
        if (it == cnt.end())
            return 0;
        auto &v = it->second;
        auto L = lower_bound(v.begin(), v.end(), startTime);
        auto R = upper_bound(v.begin(), v.end(), endTime);
        return (int)(R - L);
    }
};