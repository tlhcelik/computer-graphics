**DDA Algorithm**: _**D**igital **D**ifferential **A**nalyzer (graphics algorithm)_

<p align="center">
<img width="550" height="400" src="https://github.com/tlhcelik/computer-graphics/blob/master/w1/dda.png">
</p>

DDA is a computer graphics and draw line on the computer fundamentals. Draw to some line _y = mx + a_ use y point diff. and x point diff.

**Δx = x1 − x0**

**Δy = y1 − y0**

**Xdiff = |(x1 - x2)| / max_using_pixel_of_x_line**

**Ydiff = |(y1 - y2)| / max_using_pixel_of_y_line**

This pixel table don't have float numbers,for this reason round all diff numbers. **round _Xdiff and Ydiff_**

  example:
  Xdiff = round(Xdiff)

This formula must know to slope _y = **m**x + a_ for next pixel.

**m = Δy/Δx** (m is a line slope)

**Next pixel finding:**

X(n+1) = Xn + Xdiff

Y(n+1) = Yn + Ydiff

**DDA Algorithm Code on Qt Creator 5.5**
```cpp
    void graphic::cidDDA()
{
    double dx = last_point.x() - first_point.x();
    double dy = last_point.y() - last_point.y();
    double x_diff, y_diff;
    double max_using_pixel; 
    double x, y;

    if (fabs(dx) > fabs(dy)) {
        adim = fabs(dx);
    } else {
        adim = fabs(dy);
    }

    x_diff = dx / max_using_pixel;
    y_diff = dy / max_using_pixel;

    x = first_point.x();
    y = first_point.y();

    for (int i = 0; i < max_using_pixel; ++i) {
        x += x_diff; //Xn+1 = Xn + Xfark;
        y += y_diff;

        res.setPixel(round(x),round(y),qRgb(255,0,0));
        setPixmap(QPixmap::fromImage(res));
        QApplication::processEvents();

    }
}

```

<p align="center">
<img width="550" height="400" src="https://github.com/tlhcelik/computer-graphics/blob/master/w1/ss.png">
</p>
