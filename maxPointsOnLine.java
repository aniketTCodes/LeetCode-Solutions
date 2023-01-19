import java.util.*;
import java.math.*;

class Line{
    double m;
    double c;
    Set<ArrayList<Integer>> points;
    Line(int x1,int y1,int x2,int y2){
        this.m=(1.0*Math.abs(y2-y1))/Math.abs(x2-x1);
        ArrayList<Integer> p1=new ArrayList<>();
        p1.add(x1);
        p1.add(y2);
        ArrayList<Integer> p2=new ArrayList<>();
        p2.add(x1);
        p2.add(y2);
        points.add(p1);
        points.add(p2);
    }
    @Override
    public int hashCode(){
        int temp=14;
        return temp*(int)m+temp*(int)c; 
    }
    @Override
    public boolean equals(Object o){
        Line other=(Line)o;
        return this.m==other.m&&this.c==other.c;
    }
    public int points(){
        return points.size();
    }
}

class Solution {
    public int maxPoints(int[][] points) {
        Set<Line> lines=new HashSet<>();
        int max=0;
        for(int i=0;i<points.length;i++){
            for(int j=i+1;j<points.length;j++){
                Line l=new Line(points[i][0], points[i][1],points[j][0], points[j][1]);
                if(!lines.add(l)){
                    lines.
                }
            }
        }
    }
}