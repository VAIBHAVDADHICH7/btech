// Exp 1: Android Hello World Activity
package com.rtu.madlab;

import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class HelloWorldActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TextView tv = new TextView(this);
        tv.setText("Hello World - RTU Mobile App Development Lab!");
        tv.setTextSize(22f);
        setContentView(tv);
    }
}
