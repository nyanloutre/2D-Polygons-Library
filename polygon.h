/**
 * ######################
 * # A14 - LO27 PROJECT #
 * ######################
 *
 * Created by Maxime Brodat and Stéphane Perrez
 *
 * Deadline of the project: 01/05/2015
 */

/**
 * DESCRIPTION OF THE FILE:
 * ------------------------
 * This file is used to all data types and functions related to polygons.
 */

#ifndef POLYGON_H
#define POLYGON_H

/* ----- INCLUDE ----- */

#include <boolean.h>
#include <status_enum.h>

/* ----- TYPEDEF ----- */

/**
 * Data type of a point in a 2D-plane with the following specifications:
 * x - real number containing the abscissa of the point
 * y - real number containing the ordinate of the point
 */
typedef struct
{
    double x;
    double y;
} Point;

/**
 * Data type of an element of the polygon-linked-list with the following specifications:
 * value - Point data type with the abscissa and ordinate of the point
 * index - index of the point contained in the polygon from 1 to size
 * prev - pointer on the previous element of the polygon
 * next - pointer on the next element of the polygon
 */
typedef struct elem
{
    Point value;
    int index;
    struct elem* prev;
    struct elem* next;
} Element;

/**
 * Data type of a polygon defined as a linked list containing the elements defined above
 * This data type is defined with the following specifications:
 * head - pointer on the first element of the polygon
 * size - number of elements within the polygon
 */
typedef struct
{
    Element* head;
    int size;
} Polygon;

/* ----- PROTOTYPES ----- */

/**
 * Adds the specified point at the end of the specified polygon
 * polygon - polygon to which we want to add a point
 * point - point we want to add at the end of the polygon
 * Returns the polygon containing the new point
 */
Polygon addPoint (Polygon polygon, Point point);

/**
 * Gives a sorted version of a polygon, in ascendant order from the vector of a point with his projection on y
 * polygon - the Polygon to sort
 * point - the Point defining the vector
 * Returns the sorted version of polygon
 */
Polygon angleSortPolygon (Polygon polygon, Point point);

/**
 * Computes the angle from 3 points
 * p1, p2, p3 - the three points
 * Returns the angle (p1p2p3) in radians, and 4 if two p1 or p2 equal p3
 */
float angleThreePoints(Point p1, Point p2, Point p3);

/**
 * Checks if two polygons are the same
 * p1, p2 - the two tested polygons
 * Returns TRUE if p1 and p2 are equal, FALSE otherwise
 */
Boolean areEqualPolygons (Polygon p1, Polygon p2);

/**
 * Checks if two points have the same coordinates
 * po1, po2 - the two points to check
 * Returns TRUE if the points are equal, FALSE otherwise
 */
Boolean arePointsEqual (Point po1, Point po2);

/** Create a new polygon that is the central symmetry of a specified polygon according to a specified point
 * p - the polygon for which the symmetry is computed
 * s - the point of symmetry
 * Return the polygon symmetric to p according to s
 */
Polygon centralSymmetry (Polygon p, Point s);

/**
 * Shows if a point is contained within a polygon
 * polygon - polygon in which we want to know if the point is included
 * point - point we want to know if included or not in the polygon
 * Returns TRUE if the point is inside the polygon, FALSE otherwise
 */
Boolean containsPoint (Polygon polygon, Point point);

/**
 * Shows if a polygon is inside, outside, equal, intersecting or enclosing an other polygon
 * p1, p2 - the two polygons tested
 * Returns the corresponding value of Status, and error if one of the polygons is not valid (less than 3 points)
 */
Status containsPolygon (Polygon p1, Polygon p2);

/**
 * Compute the convex hull of a list of point
 * polygon - the list of points
 * Return the convex hull of polygon
 */
Polygon convexhullPolygon (Polygon polygon);

/**
 * Creates a 2D-Point according to the Point data type
 * newX - abscissa coordinate
 * newY - ordinate coordinate
 * Returns the newly created point
 */
Point createPoint (double newX, double newY);

/**
 * Creates an empty polygon
 * Returns the newly created empty polygon
 */
Polygon createPolygon ();

/**
 * Empties a polygon's data
 * polygon - specified polygon to empty
 * Returns the empty polygon
 */
Polygon emptyPolygon (Polygon polygon);

/**
 * Checks if two polygons have the same shape
 * p1, p2 - the two tested polygons
 * Returns TRUE if p1 and p2 have the same shape, FALSE otherwise
 */
Boolean haveSameShapePolygons (Polygon p1, Polygon p2);

/**
 * Checks if two segments do intersect
 * A1, A2 - the two points defining the first tested segment
 * B1, B2 - the two points defining the second tested segment
 * Returns TRUE if the two lines intersect each other, FALSE otherwise
 * If the result is TRUE, the coordinates of the intersection point will be stored in the pointer i*
 */
Boolean intersectionSegments (Point A1, Point A2, Point B1, Point B2, Point* i);

/**
 * Checks if a polygon is in another one
 * p1, p2 - the two tested polygons
 * Returns TRUE if p1 is within p2 (inside or equal), FALSE otherwise
 */
Boolean isInsidePolygon (Polygon p1, Polygon p2);

/**
 * Checks if a point is or not on a finite line
 * A, B - define the segment [A,B] to check
 * P - point to check
 * Returns TRUE if P is on [A,B], FALSE otherwise
 */
Boolean isOnTheLine (Point A, Point B, Point P);

/**
 * Checks if a polygon is outside another one
 * p1, p2 - the two tested polygons
 * Returns TRUE if p1 is outside of p2, FALSE otherwise
 */
Boolean isOutsidePolygon (Polygon p1, Polygon p2);

/**
 * Checks if a polygon is really a polygon
 * polygon - list of points to test
 * Returns TRUE if the argument is really a polygon, FALSE otherwise
 */
Boolean isPolygon (Polygon polygon);

/**
 * Computes the length of a vector
 * A, B - points composing the vector AB to study
 */
double lengthVector (Point A, Point B);

/**
 * Displays int the console the coordinates of the specified point
 * point - point containing the coordinates to display
 */
void printPoint (Point point);

/**
 * Displays the coordinates of all points of a specified polygon
 * polygon - specified polygon to display
 */
void printPolygon (Polygon polygon);

/**
 * Removes a specified point from the specified polygon
 * polygon - polygon for which we want to remove a point
 * i - index of the point we want to remove
 * Returns the polygon without the specified point
 */
Polygon removePoint (Polygon polygon, int i);

/**
 * Computes the rotation of a polygon according to a point and an angle in radians (counterclockwise)
 * poly - polygon about to be rotated
 * center - point of rotation of the polygon
 * angle - angle counterclockwise of rotation in radians
 */
Polygon rotatePolygon (Polygon poly, Point center, float angle);

/**
 * Scales a polygon according to a factor
 * poly - specified polygon to scale
 * factor - scale factor to use
 * Returns the scaled polygon
 */
Polygon scalePolygon (Polygon poly, float factor);

/**
 * Outputs the list of points of a polygon into a string
 * polygon - polygon to output
 * Returns the array of characters containing the list of points formated
 */
char* toString (Polygon polygon);

/**
 * Computes the translation of a polygon according to the vector defined by two points
 * poly - specified polygon to translate
 * A, B - two points forming the vector AB
 * Returns the translated polygon
 */
Polygon translatePolygon (Polygon poly, Point A, Point B);

/**
 * Computes the union between the two specified polygons
 * poly1, poly2 - the two polygons to merge
 */
Polygon unionPolygons (Polygon poly1, Polygon poly2);

#endif
