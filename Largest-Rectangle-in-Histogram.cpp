inline int _max(int a, int b){
    return a > b ? a : b;
}

inline int _min(int a, int b){
    return a > b ? b : a;
}

int _calc_max_(vector<int> &height, int start, int mid, int end){
    int val = _min(height[mid], height[mid + 1]);
    int cnt = 2;
    int max = val * 2;
    int lidx = mid - 1;
    int ridx = mid + 2;

    while(true){
        int lbreak = lidx < start;
        int rbreak = ridx > end;
        if(lbreak && rbreak){
            break;
        }

        int x = 0;
        int merge_left = 0;
        if(lbreak){
            x = height[ridx];
            merge_left = 0;
        }
        else if(rbreak){
            x = height[lidx];
            merge_left = 1;
        }
        else{
            int lval = height[lidx];
            int rval = height[ridx];
            if(lval >= rval){
                x = lval;
                merge_left = 1;
            }
            else{
                x = rval;
                merge_left = 0;
            }
        }

        int total = _min(x, val) * (cnt + 1);
        if(total >= max){
            max = total;
            val = _min(x, val);
            cnt = cnt + 1;

            if(merge_left)
                lidx = lidx - 1;
            else
                ridx = ridx + 1;
        }
        else{
            break;
        }
    }
    return max;
}

int _largest(vector<int> &height, int start, int end){
    if(end - start < 0){
        return 0;
    }
    if(end - start == 0){
        return height[start];
    }
    else if(end - start == 1){
        return _max(_max(height[start], height[end]), _min(height[start], height[end]) * 2);
    }
    else{
        int mid = (start + end) / 2;
        int lmax = _largest(height, start, mid);
        int rmax = _largest(height, mid + 1, end);
        int max = _calc_max_(height, start, mid, end);
        return _max(max, _max(lmax, rmax));
    }
}

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return _largest(height, 0, (int)height.size() - 1);
    }
};