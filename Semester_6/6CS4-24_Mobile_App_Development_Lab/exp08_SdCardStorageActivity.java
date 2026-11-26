// Exp 8: Write Data to External Storage (App-specific SD Card Directory)
package com.rtu.madlab;

import android.os.Bundle;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import java.io.*;

public class SdCardStorageActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        File file = new File(getExternalFilesDir(null), "lab_log.txt");
        try (FileOutputStream fos = new FileOutputStream(file)) {
            fos.write("Saved from Android MAD Lab!".getBytes());
            Toast.makeText(this, "Saved to " + file.getAbsolutePath(), Toast.LENGTH_LONG).show();
        } catch (IOException e) {
            Toast.makeText(this, "Error: " + e.getMessage(), Toast.LENGTH_SHORT).show();
        }
    }
}
