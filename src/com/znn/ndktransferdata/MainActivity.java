package com.znn.ndktransferdata;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity {

	public native int add(int a, int b);
	public native String doString(String s);
	public native int[] doArray(int[] nums);
	static{
		System.loadLibrary("Hello");
	}
	private Button button1;
	private Button button2;
	private Button button3;
	private TextView infoTextView;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		button1 = (Button) findViewById(R.id.btn1);
		button2 = (Button) findViewById(R.id.btn2);
		button3 = (Button) findViewById(R.id.btn3);
		infoTextView = (TextView) findViewById(R.id.txtinfo);
		
		button1.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				infoTextView.setText("12+21="+add(12, 21));
			}
		});
		button2.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				infoTextView.setText("Zhangningning=>"+doString("Zhangningning"));
			}
		});
		button3.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				int[] arr = doArray(new int[]{1,2,3});
				infoTextView.setText("Array[1,2,3]=>"+arr[0]+" "+arr[1]+" "+arr[2]);
			}
		});
	}

}
