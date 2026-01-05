class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //Paper
        int pickP = 0;
        int travelP = 0;
        int lastHouseP = 0;

        //Glass
        int pickG = 0;
        int travelG = 0;
        int lastHouseG = 0;

        //Metal
        int pickM = 0;
        int travelM = 0;
        int lastHouseM = 0;

        for(int i=0 ; i<garbage.size() ; i++){
            string currHouse = garbage[i];

            for(int j=0 ; j<currHouse.length() ; j++){
                char garbageType = currHouse[j];

                if(garbageType == 'P'){
                    pickP++;
                    lastHouseP = i;
                }
                if(garbageType == 'G'){
                    pickG++;
                    lastHouseG = i;
                }
                if(garbageType == 'M'){
                    pickM++;
                    lastHouseM = i;
                }
            }
        }

        for(int i=0 ; i<lastHouseP ; i++){
            travelP = travelP + travel[i];
        }
        for(int i=0 ; i<lastHouseM ; i++){
            travelM = travelM + travel[i];
        }
        for(int i=0 ; i<lastHouseG ; i++){
            travelG = travelG + travel[i];
        }

        return (travelP + travelM + travelG + pickM + pickG + pickP);
    }
};