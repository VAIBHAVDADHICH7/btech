// Exp 6: SQLite Database Creation & CRUD Operations
package com.rtu.madlab;

import android.content.*;
import android.database.Cursor;
import android.database.sqlite.*;

public class SQLiteCrudHelper extends SQLiteOpenHelper {
    public SQLiteCrudHelper(Context ctx) { super(ctx, "CampusDB", null, 1); }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("CREATE TABLE notes (id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT, body TEXT)");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldV, int newV) {
        db.execSQL("DROP TABLE IF EXISTS notes"); onCreate(db);
    }

    public long insertNote(String title, String body) {
        ContentValues cv = new ContentValues();
        cv.put("title", title); cv.put("body", body);
        return getWritableDatabase().insert("notes", null, cv);
    }

    public Cursor getAllNotes() {
        return getReadableDatabase().rawQuery("SELECT * FROM notes", null);
    }
}
