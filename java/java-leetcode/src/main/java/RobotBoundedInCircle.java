// LC-1041
public class RobotBoundedInCircle
{
    public boolean isRobotBounded(String instructions) {
        int vecX = 0; // x coordinate of direction vector
        int vecY = 1; // y coordinate of direction vector
        int posX = 0; // x coordinate of robot
        int posY = 0; // y coordinate of robot
        for (int i = 0; i < instructions.length(); ++i) {
            char c = instructions.charAt(i);
            if (c == 'G') {
                posX += vecX;
                posY += vecY;
            }
            else if (c == 'L') {
                int tmp = vecX;
                vecX = -1 * vecY;
                vecY = tmp;
            }
            else {
                int tmp = vecX;
                vecX = vecY;
                vecY = -1 * tmp;
            }
        }
        if (posX == 0 && posY == 0) return true;
        return vecX != 0 || vecY != 1;
    }
}
