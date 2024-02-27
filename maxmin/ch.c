#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
};

int compare(const void *a, const void *b) {
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    return (p1->x - p2->x);
}

int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(struct Point points[], int n) {
    if (n < 3) return;

    struct Point hull[n];
    int hullSize = 0;

    int leftmost = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[leftmost].x)
            leftmost = i;

    int p = leftmost, q;
    do {
        hull[hullSize++] = points[p];
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    } while (p != leftmost);

    printf("Convex Hull:\n");
    for (int i = 0; i < hullSize; i++)
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
}

int main() {
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    struct Point *points = malloc(num_points * sizeof(struct Point));
    if (points == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the coordinates of each point:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Point %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    qsort(points, num_points, sizeof(struct Point), compare);
    convexHull(points, num_points);

    free(points);
    return 0;
}
