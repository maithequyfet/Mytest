package com.example.a4000221.aoc_04_findworkout;

import android.app.Activity;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Spinner;
import android.widget.TextView;


public class FindWorkoutActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_find_workout);
    }

    public void onClickFindWorkout(View view){
        TextView workouts = (TextView) findViewById(R.id.textViewID);
        Spinner workoutType = (Spinner) findViewById(R.id.workoutTypeID);
        String workout = String.valueOf(workoutType.getSelectedItem());
        workouts.setText(workout);

    }
}
