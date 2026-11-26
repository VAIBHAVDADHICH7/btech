// Exp 7: GPS Location Activity (Requires ACCESS_FINE_LOCATION permission)
package com.rtu.madlab;

import android.annotation.SuppressLint;
import android.location.*;
import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class GpsLocationActivity extends AppCompatActivity {
    @SuppressLint("MissingPermission")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TextView tv = new TextView(this);
        setContentView(tv);
        LocationManager lm = (LocationManager) getSystemService(LOCATION_SERVICE);
        lm.requestLocationUpdates(LocationManager.GPS_PROVIDER, 2000, 5, loc ->
            tv.setText("Lat: " + loc.getLatitude() + ", Lon: " + loc.getLongitude()));
    }
}
