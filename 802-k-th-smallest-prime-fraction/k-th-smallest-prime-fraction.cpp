class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1;

        while (true) {
            double mid = (left + right) / 2;

            int count = 0;
            double maxFrac = 0;
            int num = 0, den = 1;

            int j = 1;

            for (int i = 0; i < n - 1; i++) {
                while (j < n && arr[i] > mid * arr[j]) j++;

                if (j == n) break;

                count += (n - j);

                double frac = (double)arr[i] / arr[j];
                if (frac > maxFrac) {
                    maxFrac = frac;
                    num = arr[i];
                    den = arr[j];
                }
            }

            if (count == k) return {num, den};
            else if (count < k) left = mid;
            else right = mid;
        }
    }
};