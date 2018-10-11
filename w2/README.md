**Midpoint Drawing Circle**

<p align="center">
<img width="400" height="400" src="https://github.com/tlhcelik/computer-graphics/blob/master/w2/mirroring.png">
</p>

When draw circle you must know is **rotate degree** and **first x,y points**.
_Following method draw your own circle but other algorithm _(Bresenham draw circle alg.)_ make this faster then._

If x0 and y0 points equal to 0,0 use this formula : 

**x1 = cos(degree) * radius**

**y1 = sin(degree) * radius**

when x0 and y0 points is different origin, use this formula : 

**x1 = Xk + (cos(degree) * radius)**

**y1 = Yk + (sin(degree) * radius)**

This method draw circle counterclockwise and step by step but also consume a lot of time.

```c
void draw_circle_iterative_method(int radius, int x0, int y0)
{
  float angle = 0.0;
  while(angle <= 360.0)
  {
    x = x0 + (cos(angle) * radius);
    y = y0 + (sin(angle) * radius);
    
    putPixel(x,y);
    
    angle += 1.0;
  }
}
```

Bresenham Draw Circle Algorithm :books: [Go to PDF](https://github.com/tlhcelik/computer-graphics/edit/master/w2/bresenham-circle-algorithm.pdf)
