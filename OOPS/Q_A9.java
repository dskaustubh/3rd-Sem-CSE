abstract class Reservation {
    abstract boolean reserve(int s, String type);

    abstract int getAvailableSeats(String s);
}

class ReserveBus extends Reservation {
    int totalSeats;
    int n = 0;

    ReserveBus(int totalSeats) {
        this.totalSeats = totalSeats;
    }

    boolean reserve(int s, String type) {
        if (s < getAvailableSeats(type)) {
            n = n + s;
            return true;
        } else {
            return false;
        }
    }

    int getAvailableSeats(String s) {
        return totalSeats - n;
    }
}

class ReserveTrain extends Reservation {
    int upperBerthTotalSeats, middleBerthTotalSeats, lowerBerthTotalSeats;
    int nu = 0, nm = 0, nl = 0;

    ReserveTrain(int upperBerthTotalSeats, int middleBerthTotalSeats, int lowerBerthTotalSeats) {
        this.upperBerthTotalSeats = upperBerthTotalSeats;
        this.middleBerthTotalSeats = middleBerthTotalSeats;
        this.lowerBerthTotalSeats = lowerBerthTotalSeats;
    }

    boolean reserve(int s, String type) {
        switch (type) {
        case "Upper": {
            if (s < getAvailableSeats(type)) {
                nu = nu + s;
                return true;
            } else {
                return false;
            }
        }
        case "Middle": {
            if (s < getAvailableSeats(type)) {
                nm = nm + s;
                return true;
            } else {
                return false;
            }
        }
        case "Lower": {
            if (s < getAvailableSeats(type)) {
                nl = nl + s;
                return true;
            } else {
                return false;
            }
        }
        default:
            return false;
        }
    }

    int getAvailableSeats(String s) {
        switch (s) {
        case "Upper": {
            return upperBerthTotalSeats - nu;
        }
        case "Middle": {
            return middleBerthTotalSeats - nm;
        }
        case "Lower": {
            return lowerBerthTotalSeats - nl;
        }
        default:
            return -1;
        }
    }
}

public class testa9 {
    public static void main(String[] args) {
        ReserveBus rb = new ReserveBus(25);
        if (rb.reserve(12, "sitting"))
            System.out.println("Booked");
        else
            System.out.println("Not booked");
        System.out.println(rb.getAvailableSeats("Sitting"));
        ReserveTrain rt = new ReserveTrain(25, 25, 25);
        if (rt.reserve(12, "Upper"))
            System.out.println("Booked");
        else
            System.out.println("Not booked");
        System.out.println(rt.getAvailableSeats("Upper"));
        if (rt.reserve(12, "Middle"))
            System.out.println("Booked");
        else
            System.out.println("Not booked");
        System.out.println(rt.getAvailableSeats("Middle"));
        if (rt.reserve(12, "Lower"))
            System.out.println("Booked");
        else
            System.out.println("Not booked");
        System.out.println(rt.getAvailableSeats("Lower"));
    }
}
