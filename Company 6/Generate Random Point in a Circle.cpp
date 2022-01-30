class Solution {
public:
    double r;
    double cx,cy;
    Solution(double radius, double x_center, double y_center) 
    {
        r = radius;
        cx = x_center;
        cy = y_center;
    }
    vector<double> randPoint() 
    {
        double ran1 = (double)rand() / RAND_MAX;
        double ran2 = (double)rand() / RAND_MAX;

        double angle = ran1 * 360;
        //spread points outwards, not single dimension, but two dimension  
        //KEY POINT: IF WE DO NOT TAKE THE SQUARE ROOT, WE WILL HAVE MANY POINTS CLOSE TO THE CENTRE THAN FAR AWAY.
        double radius = sqrt(ran2) * r;

        vector<double> ans;
        ans.push_back(cx + radius * sin(angle)); //x = rcosθ
        ans.push_back(cy + radius * cos(angle)); //y = rsinθ
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */