// Exp 4: RSS Feed XML Parser Activity
package com.rtu.madlab;

import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import org.xmlpull.v1.*;
import java.net.URL;
import java.util.concurrent.Executors;

public class RssFeedActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TextView tv = new TextView(this);
        setContentView(tv);
        Executors.newSingleThreadExecutor().execute(() -> {
            try {
                XmlPullParser parser = XmlPullParserFactory.newInstance().newPullParser();
                parser.setInput(new URL("https://feeds.bbci.co.uk/news/technology/rss.xml").openStream(), null);
                StringBuilder sb = new StringBuilder();
                int event = parser.getEventType();
                while (event != XmlPullParser.END_DOCUMENT) {
                    if (event == XmlPullParser.START_TAG && "title".equals(parser.getName())) {
                        sb.append("- ").append(parser.nextText()).append("\n");
                    }
                    event = parser.next();
                }
                runOnUiThread(() -> tv.setText(sb.toString()));
            } catch (Exception e) {
                runOnUiThread(() -> tv.setText("RSS Error: " + e.getMessage()));
            }
        });
    }
}
