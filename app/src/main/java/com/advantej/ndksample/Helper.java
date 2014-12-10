package com.advantej.ndksample;

import android.content.Context;
import android.content.Intent;

/**
 * Created by advantej on 12/10/14.
 */
public class Helper {

    private Context mContext;
    private Intent mStartServiceIntent;

    public Helper(Context context) {
        mContext = context;
        mStartServiceIntent = new Intent(mContext, DummyService.class);
    }

    public native void doAwesomeTask(String someArg);

    //Called by native code
    public void startService() {
        mContext.startService(mStartServiceIntent);
    }

    //Called by native code
    public void stopService() {
        mContext.stopService(mStartServiceIntent);
    }
}
