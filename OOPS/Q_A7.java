class Person {
    private String name;
    private String address;

    Person(String name, String address) {
        this.name = name;
        this.address = address;
    }

    String getName() {
        return name;
    }

    String getAddress() {
        return address;
    }

    void setAddress(String address) {
        this.address = address;
    }

    public String toString() {
        return name + "(" + address + ")";
    }
}

class Student extends Person {
    int numCourses = 0;
    String courses[] = new String[30];
    int grades[] = new int[30];

    Student(String name, String address) {
        super(name, address);
    }

    void addCourseGrade(String course, int grade) {
        if (numCourses <= 29) {
            courses[numCourses] = course;
            grades[numCourses] = grade;
            numCourses++;
        } else {
            System.out.println("Maximum number of courses");
        }
    }

    void printGrades() {
        for (int i = 0; i < numCourses; i++)
            System.out.println("Course:" + courses[i] + " Grade:" + grades[i]);
    }

    double getAverageGrades() {
        double d = 0;
        for (int i = 0; i < numCourses; i++)
            d = d + grades[i];
        d = d / numCourses;
        return d;
    }

    public String toString() {
        return getName() + "(" + getAddress() + ")";
    }
}

class Teacher extends Person {
    int numCourses = 0;
    String courses[] = new String[5];

    Teacher(String name, String address) {
        super(name, address);
    }

    boolean addCourse(String course) {
        if (numCourses <= 4) {
            for (int i = 0; i < numCourses; i++)
                if (courses[i].equals(course))
                    return false;
            courses[numCourses] = course;
            numCourses++;
            return true;
        } else
            return false;
    }

    boolean removeCourse(String course) {
        if (numCourses != 0) {
            for (int i = 0; i < numCourses; i++)
                if (courses[i].equals(course)) {
                    courses[i] = " ";
                    return true;
                }
            return false;
        }
        return false;
    }

    public String toString() {
        return getName() + "(" + getAddress() + ")";
    }
}

public class testa7 {
    public static void main(String[] args) {
        Student s = new Student("AA", "BB");
        System.out.println(s);
        s.addCourseGrade("Maths", 85);
        s.addCourseGrade("OOPS", 80);
        s.addCourseGrade("DS", 75);
        s.addCourseGrade("DMS", 70);
        s.printGrades();
        System.out.println(s.getAverageGrades());
        Teacher t = new Teacher("CC", "DD");
        if (t.addCourse("Maths"))
            System.out.println("Course added");
        else
            System.out.println("Max limit reached/course already exists");
        if (t.addCourse("Maths"))
            System.out.println("Course added");
        else
            System.out.println("Max limit reached/course already exists");
        if (t.addCourse("OOPS"))
            System.out.println("Course added");
        else
            System.out.println("Max limit reached/course already exists");
        if (t.addCourse("DS"))
            System.out.println("Course added");
        else
            System.out.println("Max limit reached/course already exists");
        if (t.removeCourse("Maths"))
            System.out.println("Course removed");
        else
            System.out.println("Zero courses/course does not exist");
        if (t.removeCourse("TOC"))
            System.out.println("Course removed");
        else
            System.out.println("Zero courses/course does not exist");
    }
}