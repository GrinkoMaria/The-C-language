// Только для анализа. НЕ запускайте этот фрагмент.
int sum(const int* a, int n) {
    int total = 0;
    for (int i = 0; i <= n; ++i) total += a[i];
    return total;
}
void writeResult(int* out, int value) {
    *out = value;
}
// Вызов: int a[]{4, 5, 6}; sum(a, 3);
// Вызов: writeResult(nullptr, 10);
