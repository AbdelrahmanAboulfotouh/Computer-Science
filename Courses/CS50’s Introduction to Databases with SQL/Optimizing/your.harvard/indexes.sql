CREATE INDEX "enrollments_BY_student_id" ON "enrollments"("student_id");
CREATE INDEX "enrollments_BY_course_id" ON "enrollments"("course_id");
CREATE INDEX "courses_BY_department" ON "courses" ("department")
WHERE "semester" = 'Fall 2023' ;
CREATE INDEX "courses_by_semester" ON "courses"("semester");
CREATE INDEX "satisfies_BY_course_id" ON "satisfies"("course_id");
