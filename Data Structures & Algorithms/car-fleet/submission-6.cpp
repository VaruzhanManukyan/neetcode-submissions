class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.empty()) {
            return 0;
        }

        std::vector<std::pair<int, int>> cars;
        for (std::size_t i = 0; i < position.size(); ++i) {
            cars.push_back({position[i], speed[i]});
        }
 
        std::sort(cars.begin(), cars.end(), [](const auto& first, const auto& second){
            return first.first > second.first;
        });

        double fleet_time = static_cast<double>((target - cars[0].first) / cars[0].second);
        int fleets = 1;

        for (std::size_t i = 1; i < cars.size(); ++i) {
            double time = static_cast<double>(target - cars[i].first) / cars[i].second;
            if (time > fleet_time) {
                fleet_time = time;
                ++fleets;
            }
        }

        return fleets;
    }
};
