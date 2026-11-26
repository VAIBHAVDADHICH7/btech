// Exp 5: Custom View Drawing Graphical Primitives (Line, Circle, Rectangle)
package com.rtu.madlab;

import android.content.Context;
import android.graphics.*;
import android.view.View;

public class GraphicsPrimitivesView extends View {
    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
    public GraphicsPrimitivesView(Context ctx) { super(ctx); }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        paint.setColor(Color.BLUE);
        canvas.drawRect(50, 50, 300, 200, paint);
        paint.setColor(Color.RED);
        canvas.drawCircle(200, 400, 100, paint);
        paint.setColor(Color.GREEN);
        paint.setStrokeWidth(8f);
        canvas.drawLine(50, 550, 400, 550, paint);
    }
}
