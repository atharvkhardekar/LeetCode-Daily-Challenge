// LeetCode Problem No. 1912
// Daily Challenge - 21/09/2025

using int2 = pair<int, int>;       
using int3 = tuple<int, int, int>; 

class MovieRentingSystem
{
public:
    unordered_map<uint64_t, int> Shop;   
    unordered_map<int, set<int2>> Movie; 
    set<int3> rented;                    

    static inline uint64_t key(int shop, int movie)
    {
        return (uint64_t)shop << 32 | movie;
    }

    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &e : entries)
        {
            int shop = e[0], movie = e[1], price = e[2];
            Shop[key(shop, movie)] = price;
            Movie[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> ans;
        auto &S = Movie[movie];
        int i = 0;
        for (auto it = S.begin(); it != S.end() && i < 5; it++, i++)
        {
            ans.push_back(it->second); 
        }
        return ans;
    }

    void rent(int shop, int movie)
    {
        int price = Shop[key(shop, movie)];
        Movie[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int price = Shop[key(shop, movie)];
        Movie[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> ans;
        int i = 0;
        for (auto it = rented.begin(); it != rented.end() && i < 5; it++, i++)
        {
            auto [price, shop, movie] = *it;
            ans.push_back({shop, movie});
        }
        return ans;
    }
};