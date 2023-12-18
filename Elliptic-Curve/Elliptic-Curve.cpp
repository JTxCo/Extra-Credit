#include <iostream>
#include <cmath>

const int p = 17;

struct Point {
    int x;
    int y;
};

bool isEqual(Point p1, Point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

Point pointAddition(Point p1, Point p2) {
    Point result;
    // Point at infinity
    if (isEqual(p1, p2) && p1.y == 0) {
        result.x = 0;
        result.y = 0;
        return result;
    }
    // Point doubling
    if (isEqual(p1, p2)) {
        int numerator = (3 * (p1.x * p1.x) + 2) % p;
        int denominator = (2 * p1.y) % p;
        int lambda = (numerator * modInverse(denominator, p)) % p;
        printf("lambda: %d\n", lambda);
        result.x = (lambda * lambda - 2 * p1.x) % p;
        result.y = (lambda * (p1.x - result.x) - p1.y) % p;
    } else {
        int numerator = (p2.y - p1.y) % p;
        int denominator = (p2.x - p1.x) % p;
        int lambda = (numerator * modInverse(denominator, p)) % p;
        printf("lambda: %d\n", lambda);
        result.x = (lambda * lambda - p1.x - p2.x) % p;
        printf("result.x: %d\n", result.x);
        result.y = (lambda * (p1.x - result.x) - p1.y) % p;
    }
    return result;
}

void do_Point_add() {
    Point p1, p2;
    p1.x = 5;
    p1.y = 1;
    p2.x = 6;
    p2.y = 3;
    Point result = pointAddition(p1, p2);
    std::cout << "The result of adding (" << p1.x << ", " << p1.y << ") and (" << p2.x << ", " << p2.y << ") is (" << result.x << ", " << result.y << ")\n";
}


