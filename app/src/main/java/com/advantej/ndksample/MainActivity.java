package com.advantej.ndksample;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends Activity {

    static {
        System.loadLibrary("MyLib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        TextView textView = (TextView) findViewById(R.id.tv);
//        textView.setText(getStringFromNative());

        Helper helper = new Helper(getApplicationContext()); // Pass the app context coz activity can die
        helper.doAwesomeTask("someTaskArg");
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if(id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

//    private native String getStringFromNative();
//
//    //Called by native code
//    public String getStringFromJava(String text) {
//        Log.d("MainActivity", "Got from JNI : " + text);
//        return "FooBar";
//    }
}

