import Graphics.circle
from Graphics import rectangle as rect
from Graphics.threedgraphics.cuboid import *
from Graphics.threedgraphics.sphere import peri as sphereperi
from Graphics.threedgraphics.sphere import area as spherearea
print("area of circle:",Graphics.circle.peri(2))
print("area of circle:",Graphics.circle.area(2))
print("peri of rectangle:",rect.peri(3,2))
print("area of rectangle:",rect.area(3,2))
print("peri of cuboid:",peri(3,2,3))
print("area of cuboid:",area(3,2,3))
print("peri of sphere:",sphereperi(5))
print("area of sphere",spherearea(5))
