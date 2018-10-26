 **Drawing Polygon**
 
 The polygons are two-dimensional closed figure made up of straight lines. In other words, it is a closed shape 
 in which each line segments 
 intersects exactly at the endpoints. Some of the polygons and non-polygons are as follows:
 
<p align="center">
<img width="700" height="350" src="https://github.com/tlhcelik/computer-graphics/blob/master/w3/polygons.png">
</p>

When polygon drawing use the DDA algorithm and points list. 

In Qt Creator list is a QList<type>.
 ```c
 QList<QPoint> points;
 points.push_back(last_point);
 points.push_back(points[0]); // adding first element to and. for this using create polygon.
    for(int i = 0; i < points.size() -1; i++){
        dda_algorithm(points[i], points[i+1]);
    }
    points.clear();
 ```
 
 ```c
 void dda_algorithm(QPoint first, QPoint last)
{
    double dx = last.x() - first.x();
    double dy = last.y() - first.y();
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
        x += x_diff; //Xn+1 = Xn + Xdiff;
        y += y_diff;

        res.setPixel(round(x),round(y),qRgb(255,0,0));
        setPixmap(QPixmap::fromImage(res));
        QApplication::processEvents();

    }
}
```

**Code Output:**

<p align="center">
<img width="400" height="400" src="https://github.com/tlhcelik/computer-graphics/blob/master/w3/draw_poly.gif">
</p>
