// Exp 2: Login Activity with Intent Navigation
package com.rtu.madlab;

import android.content.Intent;
import android.os.Bundle;
import android.widget.*;
import androidx.appcompat.app.AppCompatActivity;

public class LoginActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);
        EditText user = new EditText(this); user.setHint("Username");
        EditText pass = new EditText(this); pass.setHint("Password");
        Button btn = new Button(this); btn.setText("Login");

        btn.setOnClickListener(v -> {
            if ("admin".equals(user.getText().toString()) && "1234".equals(pass.getText().toString())) {
                Intent i = new Intent(this, HelloWorldActivity.class);
                startActivity(i);
            } else {
                Toast.makeText(this, "Invalid credentials", Toast.LENGTH_SHORT).show();
            }
        });
        layout.addView(user); layout.addView(pass); layout.addView(btn);
        setContentView(layout);
    }
}
