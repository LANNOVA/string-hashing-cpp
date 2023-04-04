#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <string_view>
 
std::string GenerateQuery(std::mt19937& generator, int max_length, int space_rate)
{
    const int length = std::uniform_int_distribution(0, max_length)(generator);
    std::string query(length, ' ');
    for (char& c : query) {
        const int rnd = std::uniform_int_distribution(0, space_rate - 1)(generator);
        if (rnd > 0) {
            c = 'a' + (rnd - 1);
        } else {
            c = '.';
        }
    }
    return query;
}
 
struct hash_index {
    size_t hash;
    size_t index;
};
hash_index find_hash_index(std::string_view cheking, std::hash<std::string>& hasher)
{
    size_t index = cheking.find_last_of(".");
    if (index == cheking.npos)
        return { (hasher(std::string { cheking })), index };
    else
        return { (hasher(std::string { cheking.substr(index + 1, cheking.size() - 1) })), index };
}
 
int main()
{
    std::vector<std::string> banned_domains;
    std::mt19937 generator;
    std::string tmp = GenerateQuery(generator, 1000, 4);
    for (int i = 0; i < 1000; ++i) {
        banned_domains.push_back(tmp);
    }
    std::vector<hash_index> hash_vector;
    std::hash<std::string> hasher {};
    for (auto const& str : banned_domains) {
        hash_vector.push_back(find_hash_index(str, hasher));
    }
    std::set<size_t> sets;
    for (auto& [h, i] : hash_vector) {
        sets.insert(h);
    }
    assert(sets.size() == 1U);
}
 
//DONATE SRAVstudios

//BTC - bc1q5kmqqynratseyh7v0n8q58rn7p5xejuemmc4px

//USDT(ETH)  - 0x8558288490E11E7F900471E7D52F0b0A0B6b8572

//USDT(SOLANA)  - 4MjmiAwiQT1cqb5fSpvdsKCabZAKxopcMsTqem9gWBqB

//USDT(POLYGON)  - 0x8558288490E11E7F900471E7D52F0b0A0B6b8572
//
//ETH  - 0x8558288490E11E7F900471E7D52F0b0A0B6b8572
