// Exp 3: Simple Calculator GUI Activity
package com.rtu.madlab;

import android.os.Bundle;
import android.widget.*;
import androidx.appcompat.app.AppCompatActivity;

public class CalculatorActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        LinearLayout root = new LinearLayout(this);
        root.setOrientation(LinearLayout.VERTICAL);
        EditText n1 = new EditText(this); n1.setHint("Number 1");
        EditText n2 = new EditText(this); n2.setHint("Number 2");
        Button addBtn = new Button(this); addBtn.setText("Add");
        TextView res = new TextView(this);

        addBtn.setOnClickListener(v -> {
            double a = Double.parseDouble(n1.getText().toString());
            double b = Double.parseDouble(n2.getText().toString());
            res.setText("Result: " + (a + b));
        });
        root.addView(n1); root.addView(n2); root.addView(addBtn); root.addView(res);
        setContentView(root);
    }
}
