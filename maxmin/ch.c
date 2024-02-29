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

void merge(struct Point points[], int start, int mid, int end, struct Point hull[], int *hullSize) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    struct Point left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = points[start + i];
    for (int j = 0; j < n2; j++)
        right[j] = points[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i].x <= right[j].x) {
            hull[k] = left[i];
            i++;
        } else {
            hull[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        hull[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        hull[k] = right[j];
        j++;
        k++;
    }

    *hullSize = k;
}

void mergeConvexHulls(struct Point points[], int start, int mid, int end, struct Point hull[], int *hullSize) {
    struct Point leftHull[mid - start + 2];
    struct Point rightHull[end - mid + 1];

    int leftHullSize = 0, rightHullSize = 0;

    for (int i = start; i <= mid; i++)
        leftHull[leftHullSize++] = points[i];

    for (int i = mid + 1; i <= end; i++)
        rightHull[rightHullSize++] = points[i];

    merge(leftHull, 0, leftHullSize - 1, leftHullSize - 1, leftHull, &leftHullSize);
    merge(rightHull, 0, rightHullSize - 1, rightHullSize - 1, rightHull, &rightHullSize);

    int i = 0, j = 0, k = start;
    while (i < leftHullSize && j < rightHullSize) {
        if (leftHull[i].x <= rightHull[j].x) {
            hull[k] = leftHull[i];
            i++;
        } else {
            hull[k] = rightHull[j];
            j++;
        }
        k++;
    }

    while (i < leftHullSize) {
        hull[k] = leftHull[i];
        i++;
        k++;
    }

    while (j < rightHullSize) {
        hull[k] = rightHull[j];
        j++;
        k++;
    }

    *hullSize = k;
}

void divideAndConquerConvexHull(struct Point points[], int start, int end, struct Point hull[], int *hullSize) {
    if (end - start + 1 <= 3) {
        for (int i = start; i <= end; i++) {
            hull[*hullSize] = points[i];
            (*hullSize)++;
        }
        return;
    }

    int mid = (start + end) / 2;

    struct Point leftHull[mid - start + 1];
    struct Point rightHull[end - mid];

    int leftHullSize = 0, rightHullSize = 0;

    divideAndConquerConvexHull(points, start, mid, leftHull, &leftHullSize);
    divideAndConquerConvexHull(points, mid + 1, end, rightHull, &rightHullSize);

    mergeConvexHulls(points, start, mid, end, hull, hullSize);
}

void convexHull(struct Point points[], int n) {
    if (n < 3) return;

    struct Point hull[n];
    int hullSize = 0;

    divideAndConquerConvexHull(points, 0, n - 1, hull, &hullSize);

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
