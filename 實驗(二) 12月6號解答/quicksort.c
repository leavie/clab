#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x, y;
} Square;

typedef struct {
	int x, y;
} Point;

int compareSqrArea(const void *p, const void *q) {
	int area1, area2;
	const Square *a1 = p, *a2 = q;

	printf("x of square one = %d, y of square one = %d\n", a1->x, a1->y);
	printf("x of square two = %d, y of square two = %d\n", a2->x, a2->y);
	area1 = a1->x * a1->y;
	area2 = a2->x * a2->y;
	printf("area1 = %d,  area2 = %d\n", area1, area2);
	if (area1 > area2)  return 1;
	else if (area1 < area2) return -1;
	else return 0;
}

int comparePoint(const void *p, const void *q) {
	double dist1, dist2;
	const Point *pt1 = p, *pt2 = q;

	dist1 = sqrt(pt1->x * pt1->x + pt1->y * pt1->y);
	dist2 = sqrt(pt2->x * pt2->x + pt2->y * pt2->y);

	if (dist1 < dist2)  return -1;
	else if (dist1 > dist2)  return 1;
	else return 0;
}

int compareStr(const void* v1, const void* v2) {
	char *const*a1 = v1, *const*a2 = v2;

	return strcmp(*a1, *a2);
}

int compareFloat(const void *p, const void *q) {
	const float *n1 = p, *n2 = q;

	if (*n1 > *n2)  return 1;
	else if (*n1 < *n2) return -1;
	else return 0;
}

int compareInt(const void *p, const void *q) {
	const int *n1 = p, *n2 = q;

	if (*n1 > *n2)  return 1;
	else if (*n1 < *n2) return -1;
	else return 0;
}



void quicksort(void *list, size_t size, int left, int right, int (*compare)(const void *, const void *)) {
	int i, j;
	void *pivot;
	if(left < right) {
		i = left;
		j = right+1;
		pivot = list+size*left;

		do {
			do i++;
			while((*compare)(pivot, list+size*i) > 0 && i<right);
			do j--;
			while((*compare)(list+size*j, pivot) > 0 && left<j);
			if(i < j) {
				void *temp = malloc(size);
				memcpy(temp, list+size*i, size);
				memcpy(list+size*i, list+size*j, size);
				memcpy(list+size*j, temp, size);
			}
		} while(i < j);

		void *temp = malloc(size);
		memcpy(temp, list+size*left, size);
		memcpy(list+size*left, list+size*j, size);
		memcpy(list+size*j, temp, size);

		quicksort(list,size, left, j-1, compare);
		quicksort(list,size, j+1, right, compare);
	}
}


int main(void) {
	int list[5] = {4, 8, 1, 3, 9};
	float numbers[5] = {2.1, 3.4, 0.9, 5.9, 4.3};
	char* str[] = {"ball", "zibra", "enthernet", "donut", "animal", "loop", "home", "opera", "how"};
	Square sq[5];
	sq[0].x = 1;
	sq[0].y = 5;
	sq[1].x = 3;
	sq[1].y = 3;
	sq[2].x = 9;
	sq[2].y = 2;
	sq[3].x = 2;
	sq[3].y = 4;
	sq[4].x = 8;
	sq[4].y = 5;

	Point pts[5];
	pts[0].x = 0;
	pts[0].y = 5;
	pts[1].x = 3;
	pts[1].y = 3;
	pts[2].x = 9;
	pts[2].y = -1;
	pts[3].x = 2;
	pts[3].y = 4;
	pts[4].x = 4;
	pts[4].y = 5;

	quicksort(list, sizeof(int), 0, 4, compareInt);
	quicksort(numbers, sizeof(float), 0, 4, compareFloat);
	quicksort(str, sizeof(char*), 0, 8, compareStr);
	quicksort(sq, sizeof(Square), 0, 4, compareSqrArea);
	quicksort(pts, sizeof(Point), 0, 4, comparePoint);

	printf("Print sorted numbers of type int:\n");
	for(int i=0; i<=4; i++)
		printf("%d ", list[i]);

	printf("\n\nPrint sorted numbers of type float:\n");
	for(int i=0; i<=4; i++)
		printf("%.2f ", numbers[i]);

	printf("\n\nPrint sorted strings:\n");
	for(int i=0; i<=8; i++)
		printf("%s ", str[i]);

	printf("\n\nPrint sorted rectangles by area (height=x and width=y):\n");
	for(int i=0; i<5; i++)
		printf("x = %d,  y = %d\n", sq[i].x, sq[i].y);

	printf("\nPrint sorted points by distance to the origin:\n");
	for(int i=0; i<5; i++)
		printf("x = %d,  y = %d\n", pts[i].x, pts[i].y);
	return 0;
}
