#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int n= stops.size();
    vector<int> x;
    
    for(int i=0;i<n;i++){
        x.push_back(stops[i]);
    }
    x.insert(x.begin(),1,0);
    x.insert(x.end(),1,dist);

    int numRefills = 0, currentRefill = 0, lastRefill = 0;
    while (currentRefill <= n){
        lastRefill= currentRefill;
        while(currentRefill<= n && (x[currentRefill+1]-x[lastRefill])<=tank ){
            currentRefill +=1;
        }
        if(currentRefill == lastRefill)
            return -1;
        if(currentRefill<=n)
            numRefills +=1;
    }
    return numRefills;
}


int main() {
    int distance = 0;
    cin >> distance;
    int tank = 0;
    cin >> tank;
    int noOfStops = 0;
    cin >> noOfStops;

    vector<int> stops(noOfStops);
    for (size_t i = 0; i < noOfStops; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(distance, tank, stops) << "\n";

    return 0;
}
