int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a > b ? b : a;
}
int maxArea(int* height, int heightSize) {
    int result = 0;
    int i = 0, j = heightSize - 1;
    while (i < j) {
        result = max(result, min(height[i], height[j]) * (j - i));
        if (height[i] < height[j]) i++;
        else j--;
    }
    return result;
}
