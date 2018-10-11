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
    
    PutPixel(x,y);
    
    angle += 1.0;
  }
}
```

Bresenham Draw Circle Algorithm :books: [Go to PDF](https://github.com/tlhcelik/computer-graphics/edit/master/w2/bresenham-circle-algorithm.pdf)

Code like this :

```c
void graphic::bresenham_with_draw_circle(int radius, int x0 ,int y0)
{

        int X, Y, XC, YC, RADIUS_ERROR;
        X = radius;
        Y = 0;
        XC = 1 - (2*radius); // x change value
        YC = 1; // y change value
        RADIUS_ERROR = 0;

        while (X >= Y) {

            PutPixel(x0 + X, y0 + Y , rgb(255,0,0));
            PutPixel(x0 - X, y0  + Y ,rgb(255,0,0));

            PutPixel(x0 - X ,y0   - Y,rgb(255,0,0));
            PutPixel(x0 + X, y0  - Y ,rgb(255,0,0));

            PutPixel(x0 + Y, y0  + X ,rgb(255,0,0));
            PutPixel(x0 - Y, y0  + X ,rgb(255,0,0));

            PutPixel(x0 - Y, y0  - X ,rgb(255,0,0));
            PutPixel(x0 + Y, y0  - X ,rgb(255,0,0));

            Y += 1;
            RADIUS_ERROR += YC;
            YC += 2;

            if ( (2 * RADIUS_ERROR) + XC > 0) {
                X -= 1;
                RADIUS_ERROR += XC;
                XC += 2;
            }
        }
}
```
**Code output :**
<p align="center">
<img width="400" height="400" src="https://github.com/tlhcelik/computer-graphics/blob/master/w2/mirror_method.gif">
</p>


