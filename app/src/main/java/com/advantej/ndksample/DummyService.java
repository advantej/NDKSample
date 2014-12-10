package com.advantej.ndksample;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

public class DummyService extends Service {

    private final static String TAG = "DummyService";

    public DummyService() {
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {

        Log.d(TAG, "DummyService Started");
        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        Log.d(TAG, "DummyService about to stop");
        super.onDestroy();
    }

    @Override
    public IBinder onBind(Intent intent) {
        Log.d(TAG, "DummyService onBind");
        return null;
    }
}
