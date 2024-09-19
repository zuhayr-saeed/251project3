#include <gtest/gtest.h>

#include "canvaslist.h"
#include "shape.h"

// TODO_STUDENT
TEST(TODO, TODO) {
  // Empty test to make this build
}

// Tests appending shapes to the end of a CanvasList
TEST(CanvasListTest, AppendToBack) {
  CanvasList myList;
  Shape *shapeA = new Shape(10, 20);
  Shape *shapeB = new Shape(30, 40);
  Shape *shapeC = new Shape();
  Shape *shapeD = new Shape(50, 60);
  ASSERT_TRUE(myList.empty());
  myList.push_back(shapeA);
  myList.push_back(shapeB);
  myList.push_back(shapeC);
  myList.push_back(shapeD);
  ASSERT_EQ(myList.size(), 4);
  ASSERT_EQ(myList.find(0, 0), 2);
  ASSERT_FALSE(myList.empty());
}

// Tests adding shapes to the end of CanvasList
TEST(CanvasList, AddToEnd) {
  CanvasList myCanvas;
  Shape *shapeFirst = new Shape(10, 20);
  Shape *shapeSecond = new Shape(30, 40);
  Shape *shapeThird = new Shape();
  Shape *shapeFourth = new Shape(50, 60);
  ASSERT_TRUE(myCanvas.empty());
  myCanvas.push_back(shapeFirst);
  myCanvas.push_back(shapeSecond);
  myCanvas.push_back(shapeThird);
  myCanvas.push_back(shapeFourth);
  ASSERT_EQ(myCanvas.size(), 4);
  ASSERT_EQ(myCanvas.find(0, 0), 2);
  ASSERT_FALSE(myCanvas.empty());
}

// Tests adding shapes to the front of CanvasList
TEST(CanvasList, AddToFront) {
  CanvasList artList;
  Shape *shapeA = new Shape(10, 20);
  Shape *shapeB = new Shape(30, 40);
  Shape *shapeC = new Shape();
  Shape *shapeD = new Shape(50, 60);
  ASSERT_TRUE(artList.empty());
  artList.push_front(shapeA);
  artList.push_front(shapeB);
  artList.push_front(shapeC);
  artList.push_front(shapeD);
  ASSERT_EQ(artList.size(), 4);
  ASSERT_EQ(artList.find(10, 20), 3);
  ASSERT_FALSE(artList.empty());
}

// Tests the find functionality of CanvasList
TEST(CanvasList, LocateShape) {
  CanvasList canvas;
  Shape *firstShape = new Shape(1, 2);
  Shape *secondShape = new Shape(3, 4);
  Shape *thirdShape = new Shape();
  Shape *fourthShape = new Shape(5, 6);
  canvas.push_back(firstShape);
  canvas.push_back(secondShape);
  canvas.push_back(thirdShape);
  canvas.push_back(fourthShape);
  ASSERT_EQ(canvas.find(0, 0), 2);
  ASSERT_EQ(canvas.find(7, 8), -1);
}

// Tests accessing a shape at a specific index in CanvasList
TEST(CanvasList, AccessShapeAtIndex) {
  CanvasList myGallery;
  Shape *shapeOne = new Shape(1, 2);
  Shape *shapeTwo = new Shape(3, 4);
  Shape *shapeThree = new Shape();
  Shape *shapeFour = new Shape(5, 6);
  myGallery.push_back(shapeOne);
  myGallery.push_back(shapeTwo);
  myGallery.push_back(shapeThree);
  myGallery.push_front(shapeFour);
  CanvasList newList;
  ASSERT_EQ(myGallery.shape_at(0), shapeFour);
  ASSERT_EQ(myGallery.shape_at(2), shapeTwo);
  ASSERT_EQ(myGallery.shape_at(5), nullptr);
  ASSERT_EQ(myGallery.shape_at(-1), nullptr);
  ASSERT_EQ(newList.shape_at(0), nullptr);
}

// Tests removing the first and last elements from a CanvasList
TEST(CanvasList, RemoveElements) {
  CanvasList artCollection;
  Shape *shapeOne = new Shape(10, 15);
  Shape *shapeTwo = new Shape(20, 25);
  Shape *shapeThree = new Shape();
  Shape *shapeFour = new Shape(30, 35);
  artCollection.push_back(shapeOne);
  artCollection.push_back(shapeTwo);
  artCollection.push_back(shapeThree);
  artCollection.push_back(shapeFour);
  Shape *removedFirst = artCollection.pop_front();
  ASSERT_EQ(removedFirst, shapeOne);
  ASSERT_EQ(artCollection.size(), 3);
  Shape *removedLast = artCollection.pop_back();
  ASSERT_EQ(removedLast, shapeFour);
  ASSERT_EQ(artCollection.size(), 2);
  delete removedFirst;
  delete removedLast;
}

// Tests the copy constructor of CanvasList
TEST(CanvasList, CopyConstructorValidation) {
  CanvasList originalList;
  Shape *shapeA = new Shape(11, 22);
  Shape *shapeB = new Shape(33, 44);
  Shape *shapeC = new Shape();
  Shape *shapeD = new Shape(55, 66);
  originalList.push_back(shapeA);
  originalList.push_back(shapeB);
  originalList.push_back(shapeC);
  originalList.push_back(shapeD);
  CanvasList copiedList = CanvasList(originalList);
  Shape *copiedShape = copiedList.shape_at(2);
  ASSERT_EQ(copiedList.size(), 4);
  ASSERT_EQ(copiedList.find(33, 44), 1);
  ASSERT_EQ(copiedList.shape_at(2), copiedShape);
  CanvasList newList;
  CanvasList copiedNewList = CanvasList(newList);
  ASSERT_EQ(copiedNewList.size(), 0);
  ASSERT_EQ(copiedNewList.front(), nullptr);
}

// Tests the assignment operator of CanvasList
TEST(CanvasList, AssignmentOperatorCheck) {
  CanvasList firstList;
  Shape *shapeAlpha = new Shape(12, 24);
  Shape *shapeBeta = new Shape(36, 48);
  Shape *shapeGamma = new Shape();
  Shape *shapeDelta = new Shape(60, 72);
  firstList.push_back(shapeAlpha);
  firstList.push_back(shapeBeta);
  firstList.push_back(shapeGamma);
  firstList.push_back(shapeDelta);
  CanvasList secondList;
  secondList = firstList;
  ASSERT_EQ(secondList.size(), 4);
  ASSERT_EQ(secondList.front()->value->getX(), 12);
  ASSERT_EQ(secondList.front()->value->getY(), 24);
  int searchResult = secondList.find(60, 72);
  int searchResultInvalid = secondList.find(74, 86);
  ASSERT_EQ(searchResult, 3);
  ASSERT_EQ(searchResultInvalid, -1);
  CanvasList thirdList;
  CanvasList fourthList = thirdList;
  ASSERT_EQ(fourthList.size(), 0);
  ASSERT_EQ(thirdList.front(), nullptr);
  ASSERT_EQ(fourthList.front(), nullptr);
}

// Tests removing a single element from CanvasList
TEST(CanvasList, RemoveSingleElement) {
  CanvasList gallery;
  Shape *elementA = new Shape(11, 21);
  gallery.push_back(elementA);
  Shape *extractedShape = gallery.pop_front();
  ASSERT_EQ(extractedShape, elementA);
  Shape *extractedShapeAgain = gallery.pop_front();
  Shape *extractedLastShape = gallery.pop_back();
  ASSERT_EQ(extractedShapeAgain, nullptr);
  ASSERT_EQ(extractedLastShape, nullptr);
  CanvasList newGallery;
  Shape *popShapeFromEmptyList = newGallery.pop_front();
  Shape *popLastShapeFromEmptyList = newGallery.pop_back();
  ASSERT_EQ(popShapeFromEmptyList, nullptr);
  ASSERT_EQ(popLastShapeFromEmptyList, nullptr);
  delete extractedShape;
}

// Tests removing an element at a specific index in CanvasList
TEST(CanvasList, DeleteAtIndex) {
  CanvasList showcase;
  Shape *shapeOne = new Shape(12, 23);
  Shape *shapeTwo = new Shape(34, 45);
  Shape *shapeThree = new Shape();
  Shape *shapeFour = new Shape(56, 67);
  showcase.push_back(shapeOne);
  showcase.push_back(shapeTwo);
  showcase.push_back(shapeThree);
  showcase.push_back(shapeFour);
  showcase.remove_at(2);
  ASSERT_EQ(showcase.size(), 3);
  Shape *remainingShape = showcase.shape_at(2);
  ASSERT_EQ(remainingShape, shapeFour);
  showcase.remove_at(0);
  ShapeNode *headNode = showcase.front();
  Shape *newFirstShape = headNode->value;
  ASSERT_EQ(newFirstShape->getX(), 34);
  ASSERT_EQ(newFirstShape->getY(), 45);
  showcase.remove_at(4);
  ASSERT_EQ(showcase.size(), 2);
  CanvasList emptyList;
  emptyList.remove_at(0);
  ASSERT_EQ(emptyList.size(), 0);
  ASSERT_EQ(emptyList.front(), nullptr);
}

// Tests clearing all elements from CanvasList
TEST(CanvasList, EmptyList) {
  CanvasList collection;
  Shape *shapeA = new Shape(13, 24);
  Shape *shapeB = new Shape(35, 46);
  Shape *shapeC = new Shape();
  Shape *shapeD = new Shape(57, 68);
  collection.push_back(shapeA);
  collection.push_back(shapeB);
  collection.push_back(shapeC);
  collection.push_back(shapeD);
  collection.clear();
  ASSERT_EQ(collection.size(), 0);
  ASSERT_EQ(collection.front(), nullptr);
  CanvasList emptyCollection;
  emptyCollection.clear();
  ASSERT_EQ(emptyCollection.size(), 0);
  ASSERT_EQ(emptyCollection.front(), nullptr);
}

// Tests the remove_every_other method of CanvasList
TEST(CanvasList, AlternateRemoval) {
  CanvasList artworkList;
  Shape *firstShape = new Shape(14, 28);
  Shape *secondShape = new Shape(42, 56);
  Shape *thirdShape = new Shape();
  Shape *fourthShape = new Shape(70, 84);
  Shape *fifthShape = new Shape(98, 112);
  Shape *sixthShape = new Shape(126, 140);
  artworkList.push_back(firstShape);
  artworkList.push_back(secondShape);
  artworkList.push_back(thirdShape);
  artworkList.push_back(fourthShape);
  artworkList.push_back(fifthShape);
  artworkList.push_back(sixthShape);
  artworkList.remove_every_other();
  ASSERT_EQ(artworkList.size(), 3);
  ASSERT_EQ(artworkList.front()->value, firstShape);
  ASSERT_EQ(artworkList.shape_at(1), thirdShape);
  ASSERT_EQ(artworkList.find(42, 56), -1);
  CanvasList emptyArtList;
  emptyArtList.remove_every_other();
  ASSERT_EQ(emptyArtList.size(), 0);
  ASSERT_EQ(emptyArtList.front(), nullptr);
}

// Tests inserting a shape at a specific index in CanvasList
TEST(CanvasList, InsertShapeAtIndex) {
  CanvasList myCollection;
  Shape *shape1 = new Shape(15, 30);
  Shape *shape2 = new Shape(45, 60);
  Shape *shape3 = new Shape();
  Shape *shape4 = new Shape(75, 90);
  myCollection.push_back(shape1);
  myCollection.push_back(shape2);
  myCollection.push_back(shape3);
  myCollection.push_back(shape4);
  Shape *insertShape = new Shape(105, 120);
  ShapeNode *initialHead = myCollection.front();
  Shape *initialFirstShape = initialHead->value;
  myCollection.insert_after(-1, insertShape);
  ASSERT_EQ(myCollection.size(), 4);
  ASSERT_EQ(myCollection.front(), initialHead);
  ASSERT_EQ(initialFirstShape, shape1);
  myCollection.insert_after(2, insertShape);
  ASSERT_EQ(myCollection.size(), 5);
  int newIndex = myCollection.find(105, 120);
  int newIndexAfterInsert = myCollection.find(75, 90);
  ASSERT_EQ(newIndex, 3);
  ASSERT_EQ(newIndexAfterInsert, 4);
  Shape *newShape = new Shape(135, 150);
  myCollection.insert_after(0, newShape);
  Shape *newSecondShape = myCollection.front()->next->value;
  ASSERT_EQ(newSecondShape->getX(), 135);
  ASSERT_EQ(newSecondShape->getY(), 150);
  myCollection.insert_after(8, newShape);
  CanvasList emptyCollection;
  emptyCollection.insert_after(0, insertShape);
  ASSERT_EQ(emptyCollection.size(), 0);
  ASSERT_EQ(emptyCollection.front(), nullptr);
}

// Tests retrieval of the X-coordinate for a Shape
TEST(ShapeProperties, RetrieveXCoordinate) {
  Shape *shapeAlpha = new Shape(20, 10);
  Shape *shapeBeta = new Shape();
  ASSERT_EQ(shapeAlpha->getX(), 20);
  ASSERT_NE(shapeBeta->getX(), 1); 
  delete shapeAlpha;
  delete shapeBeta;
}

// Tests retrieval of the Y-coordinate for a Shape
TEST(ShapeProperties, RetrieveYCoordinate) {
  Shape *shapeAlpha = new Shape(7, 14);
  Shape *shapeBeta = new Shape();
  ASSERT_EQ(shapeAlpha->getY(), 14);
  ASSERT_NE(shapeBeta->getY(), 2); 
  delete shapeAlpha;
  delete shapeBeta;
}

// Tests setting the X-coordinate for a Shape
TEST(ShapeModification, ChangeXCoordinate) {
  Shape *shapeAlpha = new Shape();
  shapeAlpha->setX(21);
  Shape *shapeBeta = new Shape();
  shapeBeta->setX(42);
  ASSERT_EQ(shapeAlpha->getX(), 21);
  ASSERT_EQ(shapeBeta->getX(), 42);
  delete shapeAlpha;
  delete shapeBeta;
}

// Tests setting the Y-coordinate for a Shape
TEST(ShapeModification, ChangeYCoordinate) {
  Shape *shapeAlpha = new Shape();
  shapeAlpha->setY(15);
  Shape *shapeBeta = new Shape();
  shapeBeta->setY(30);
  ASSERT_EQ(shapeAlpha->getY(), 15);
  ASSERT_EQ(shapeBeta->getY(), 30);
  delete shapeAlpha;
  delete shapeBeta;
}

// Tests the as_string method of Shape
TEST(ShapeDescription, StringRepresentation) {
  Shape *shapeAlpha = new Shape(15, 30);
  Shape *shapeBeta = new Shape(45, 60);
  ASSERT_EQ(shapeAlpha->as_string(), "It's a Shape at x: 15, y: 30");
  ASSERT_EQ(shapeBeta->as_string(), "It's a Shape at x: 45, y: 60");
  delete shapeAlpha;
  delete shapeBeta;
}

// Tests the copy method of Shape
TEST(ShapeDuplication, CopyShape) {
  Shape *originalShape = new Shape(10, 20);
  Shape *copiedShape = originalShape->copy();
  ASSERT_EQ(copiedShape->getX(), 10);
  ASSERT_EQ(copiedShape->getY(), 20);
  delete originalShape;
  delete copiedShape;
}

// Tests modifying the X-coordinate of a Circle
TEST(CircleBehavior, ModifyXCoordinate) {
  Circle *circleOne = new Circle(4, 6, 8);
  Circle *circleTwo = new Circle();
  Circle *circleThree = new Circle(10);
  ASSERT_EQ(circleOne->getX(), 4);
  ASSERT_EQ(circleTwo->getX(), 0);
  ASSERT_EQ(circleThree->getX(), 0);
  circleOne->setX(12);
  circleTwo->setX(14);
  circleThree->setX(16);
  ASSERT_EQ(circleOne->getX(), 12);
  ASSERT_EQ(circleTwo->getX(), 14);
  ASSERT_EQ(circleThree->getX(), 16);
  delete circleOne;
  delete circleTwo;
  delete circleThree;
}

// Tests modifying the Y-coordinate of a Circle
TEST(CircleBehavior, ModifyYCoordinate) {
  Circle *circleAlpha = new Circle(3, 5, 7);
  Circle *circleBeta = new Circle();
  Circle *circleGamma = new Circle(9);
  ASSERT_EQ(circleAlpha->getY(), 5);
  ASSERT_EQ(circleBeta->getY(), 0);
  ASSERT_EQ(circleGamma->getY(), 0);
  circleAlpha->setY(11);
  circleBeta->setY(13);
  circleGamma->setY(15);
  ASSERT_EQ(circleAlpha->getY(), 11);
  ASSERT_EQ(circleBeta->getY(), 13);
  ASSERT_EQ(circleGamma->getY(), 15);
  delete circleAlpha;
  delete circleBeta;
  delete circleGamma;
}

// Tests adjusting the radius of a Circle
TEST(CircleBehavior, RadiusAdjustments) {
  Circle *circleA = new Circle(2, 4, 6);
  Circle *circleB = new Circle();
  Circle *circleC = new Circle(8);
  ASSERT_EQ(circleA->getRadius(), 6);
  ASSERT_EQ(circleB->getRadius(), 0);
  ASSERT_EQ(circleC->getRadius(), 8);
  circleA->setRadius(10);
  circleB->setRadius(12);
  circleC->setRadius(14);
  ASSERT_EQ(circleA->getRadius(), 10);
  ASSERT_EQ(circleB->getRadius(), 12);
  ASSERT_EQ(circleC->getRadius(), 14);
  delete circleA;
  delete circleB;
  delete circleC;
}

// Tests the as_string method of Circle
TEST(CircleProperties, DescriptionAsString) {
  Circle *circleOne = new Circle(1, 3, 5);
  Circle *circleTwo = new Circle();
  Circle *circleThree = new Circle(7);
  ASSERT_EQ(circleOne->as_string(), "It's a Circle at x: 1, y: 3, radius: 5");
  ASSERT_EQ(circleTwo->as_string(), "It's a Circle at x: 0, y: 0, radius: 0");
  ASSERT_EQ(circleThree->as_string(), "It's a Circle at x: 0, y: 0, radius: 7");
  delete circleOne;
  delete circleTwo;
  delete circleThree;
}

// Tests the copy method of Circle
TEST(CircleDuplication, CloneCircle) {
  Circle *originalCircleOne = new Circle(2, 4, 6);
  Circle *clonedCircleOne = originalCircleOne->copy();
  ASSERT_EQ(clonedCircleOne->getX(), 2);
  ASSERT_EQ(clonedCircleOne->getY(), 4);
  ASSERT_EQ(clonedCircleOne->getRadius(), 6);
  delete originalCircleOne;
  delete clonedCircleOne;
}

// Tests modifying the X-coordinate of a RightTriangle
TEST(RightTriangleProperties, ChangeXCoordinate) {
  RightTriangle *triangleOne = new RightTriangle(5, 10, 15, 20);
  RightTriangle *triangleTwo = new RightTriangle();
  RightTriangle *triangleThree = new RightTriangle(25, 30);
  ASSERT_EQ(triangleOne->getX(), 5);
  ASSERT_EQ(triangleTwo->getX(), 0);
  ASSERT_EQ(triangleThree->getX(), 0);
  triangleOne->setX(35);
  triangleTwo->setX(40);
  triangleThree->setX(45);
  ASSERT_EQ(triangleOne->getX(), 35);
  ASSERT_EQ(triangleTwo->getX(), 40);
  ASSERT_EQ(triangleThree->getX(), 45);
  delete triangleOne;
  delete triangleTwo;
  delete triangleThree;
}

// Tests modifying the Y-coordinate of a RightTriangle
TEST(RightTriangleProperties, ChangeYCoordinate) {
  RightTriangle *rtA = new RightTriangle(6, 12, 18, 24);
  RightTriangle *rtB = new RightTriangle();
  RightTriangle *rtC = new RightTriangle(26, 32);
  ASSERT_EQ(rtA->getY(), 12);
  ASSERT_EQ(rtB->getY(), 0);
  ASSERT_EQ(rtC->getY(), 0);
  rtA->setY(36);
  rtB->setY(42);
  rtC->setY(48);
  ASSERT_EQ(rtA->getY(), 36);
  ASSERT_EQ(rtB->getY(), 42);
  ASSERT_EQ(rtC->getY(), 48);
  delete rtA;
  delete rtB;
  delete rtC;
}

// Tests adjusting the base of a RightTriangle
TEST(RightTriangleProperties, AdjustBaseSize) {
  RightTriangle *triangleOne = new RightTriangle(7, 14, 21, 28);
  RightTriangle *triangleTwo = new RightTriangle();
  RightTriangle *triangleThree = new RightTriangle(29, 31);
  ASSERT_EQ(triangleOne->getBase(), 21);
  ASSERT_EQ(triangleTwo->getBase(), 0);
  ASSERT_EQ(triangleThree->getBase(), 29);
  triangleOne->setBase(33);
  triangleTwo->setBase(35);
  triangleThree->setBase(37);
  ASSERT_EQ(triangleOne->getBase(), 33);
  ASSERT_EQ(triangleTwo->getBase(), 35);
  ASSERT_EQ(triangleThree->getBase(), 37);
  delete triangleOne;
  delete triangleTwo;
  delete triangleThree;
}

// Tests adjusting the height of a RightTriangle
TEST(RightTriangleProperties, AdjustHeight) {
  RightTriangle *rtA = new RightTriangle(8, 16, 24, 32);
  RightTriangle *rtB = new RightTriangle();
  RightTriangle *rtC = new RightTriangle(34, 38);
  ASSERT_EQ(rtA->getHeight(), 32);
  ASSERT_EQ(rtB->getHeight(), 0);
  ASSERT_EQ(rtC->getHeight(), 38);
  rtA->setHeight(39);
  rtB->setHeight(41);
  rtC->setHeight(43);
  ASSERT_EQ(rtA->getHeight(), 39);
  ASSERT_EQ(rtB->getHeight(), 41);
  ASSERT_EQ(rtC->getHeight(), 43);
  delete rtA;
  delete rtB;
  delete rtC;
}

// Tests the as_string method of RightTriangle
TEST(RightTriangleProperties, Description) {
  RightTriangle *rtOne = new RightTriangle(9, 18, 27, 36);
  RightTriangle *rtTwo = new RightTriangle();
  RightTriangle *rtThree = new RightTriangle(44, 46);
  ASSERT_EQ(rtOne->as_string(), "It's a Right Triangle at x: 9, y: 18 with base: 27 and height: 36");
  ASSERT_EQ(rtTwo->as_string(), "It's a Right Triangle at x: 0, y: 0 with base: 0 and height: 0");
  ASSERT_EQ(rtThree->as_string(), "It's a Right Triangle at x: 0, y: 0 with base: 44 and height: 46");
  delete rtOne;
  delete rtTwo;
  delete rtThree;
}

// Tests the copy method of RightTriangle
TEST(RightTriangleDuplication, CloneRightTriangle) {
  RightTriangle *originalRT = new RightTriangle(10, 20, 30, 40);
  RightTriangle *copiedRT = originalRT->copy();
  ASSERT_EQ(copiedRT->getX(), 10);
  ASSERT_EQ(copiedRT->getY(), 20);
  ASSERT_EQ(copiedRT->getBase(), 30);
  ASSERT_EQ(copiedRT->getHeight(), 40);
  delete originalRT;
  delete copiedRT;
}

// Tests modifying the X-coordinate of a Rectangle
TEST(RectangleProperties, ModifyXCoordinate) {
  Rect *rectOne = new Rect(10, 20, 30, 40);
  Rect *rectTwo = new Rect();
  Rect *rectThree = new Rect(50, 60);
  ASSERT_EQ(rectOne->getX(), 10);
  ASSERT_EQ(rectTwo->getX(), 0);
  ASSERT_EQ(rectThree->getX(), 0);
  rectOne->setX(70);
  rectTwo->setX(80);
  rectThree->setX(90);
  ASSERT_EQ(rectOne->getX(), 70);
  ASSERT_EQ(rectTwo->getX(), 80);
  ASSERT_EQ(rectThree->getX(), 90);
  delete rectOne;
  delete rectTwo;
  delete rectThree;
}

// Tests modifying the Y-coordinate of a Rectangle
TEST(RectangleProperties, ModifyYCoordinate) {
  Rect *rectA = new Rect(11, 22, 33, 44);
  Rect *rectB = new Rect();
  Rect *rectC = new Rect(55, 66);
  ASSERT_EQ(rectA->getY(), 22);
  ASSERT_EQ(rectB->getY(), 0);
  ASSERT_EQ(rectC->getY(), 0);
  rectA->setY(77);
  rectB->setY(88);
  rectC->setY(99);
  ASSERT_EQ(rectA->getY(), 77);
  ASSERT_EQ(rectB->getY(), 88);
  ASSERT_EQ(rectC->getY(), 99);
  delete rectA;
  delete rectB;
  delete rectC;
}

// Tests adjusting the width of a Rectangle
TEST(RectangleProperties, AdjustWidth) {
  Rect *rectOne = new Rect(12, 24, 36, 48);
  Rect *rectTwo = new Rect();
  Rect *rectThree = new Rect(60, 72);
  ASSERT_EQ(rectOne->getWidth(), 36);
  ASSERT_EQ(rectTwo->getWidth(), 0);
  ASSERT_EQ(rectThree->getWidth(), 60);
  rectOne->setWidth(84);
  rectTwo->setWidth(96);
  rectThree->setWidth(108);
  ASSERT_EQ(rectOne->getWidth(), 84);
  ASSERT_EQ(rectTwo->getWidth(), 96);
  ASSERT_EQ(rectThree->getWidth(), 108);
  delete rectOne;
  delete rectTwo;
  delete rectThree;
}

// Tests adjusting the height of a Rectangle
TEST(RectangleProperties, AdjustHeight) {
  Rect *rectA = new Rect(13, 26, 39, 52);
  Rect *rectB = new Rect();
  Rect *rectC = new Rect(65, 78);
  ASSERT_EQ(rectA->getHeight(), 52);
  ASSERT_EQ(rectB->getHeight(), 0);
  ASSERT_EQ(rectC->getHeight(), 78);
  rectA->setHeight(91);
  rectB->setHeight(104);
  rectC->setHeight(117);
  ASSERT_EQ(rectA->getHeight(), 91);
  ASSERT_EQ(rectB->getHeight(), 104);
  ASSERT_EQ(rectC->getHeight(), 117);
  delete rectA;
  delete rectB;
  delete rectC;
}

// Tests the string representation method of a Rectangle
TEST(RectangleProperties, StringRepresentation) {
  Rect *rectOne = new Rect(14, 28, 42, 56);
  Rect *rectTwo = new Rect();
  Rect *rectThree = new Rect(70, 84);
  ASSERT_EQ(rectOne->as_string(), "It's a Rectangle at x: 14, y: 28 with width: 42 and height: 56");
  ASSERT_EQ(rectTwo->as_string(), "It's a Rectangle at x: 0, y: 0 with width: 0 and height: 0");
  ASSERT_EQ(rectThree->as_string(), "It's a Rectangle at x: 0, y: 0 with width: 70 and height: 84");
  delete rectOne;
  delete rectTwo;
  delete rectThree;
}

// Tests the copy functionality of Rectangle
TEST(RectangleDuplication, CloneRectangle) {
  Rect *originalRect = new Rect(15, 30, 45, 60);
  Rect *clonedRect = originalRect->copy();
  ASSERT_EQ(clonedRect->getX(), 15);
  ASSERT_EQ(clonedRect->getY(), 30);
  ASSERT_EQ(clonedRect->getWidth(), 45);
  ASSERT_EQ(clonedRect->getHeight(), 60);
  delete originalRect;
  delete clonedRect;
}



