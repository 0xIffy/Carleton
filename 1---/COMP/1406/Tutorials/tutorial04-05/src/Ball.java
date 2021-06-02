public class Ball extends MoveableObject implements Harmful{
    private boolean 	isBeingHeld;

    public Ball(Point2D loc) {
        super(0,0,loc);
        isBeingHeld = false;
    }

    // The get/set methods
    public boolean isBeingHeld() { return isBeingHeld; }
    public void setIsBeingHeld(boolean newHoldStatus) { isBeingHeld = newHoldStatus; }

    public String toString() {
        return "Ball" + " at (" + (int)location.getX() + "," + (int)location.getY() + ") facing " + direction +
                " degrees going " + speed + " pixels per second";
    }

    public void draw(){
        System.out.println(String.format("Ball is at (%.1f,%.1f) facing %d degrees and moving at %d pixels per second",location.getX(),location.getY(),direction,speed));
    }

    public void update(){
        moveForward();
        speed--;
        if(speed < 0)
            speed = 0;
        draw();
    }

    public int getDamageAmount(){
        return -200;
    }
}