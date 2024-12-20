CREATE TABLE `Users`(
    `id` INT AUTO_INCREMENT,
    `first_name` varchar(35) NOT NULL,
     `last_name` varchar(35) NOT NULL,
      `username` varchar(35) NOT NULL ,
      `password` varchar(255) NOT NULL,
      PRIMARY KEY(`id`)
);
CREATE TABLE `Schools_and_Universities` (
    `id` INT AUTO_INCREMENT,
    `school_name`  varchar(35) NOT NULL,
    `school_type` varchar(35)  NOT NULL,
    `school_location` varchar(50)  NOT NULL,
    `foundation_year` INT NOT NULL,
    PRIMARY KEY(`id`)

);
CREATE TABLE `Companies`(
    `id` INT AUTO_INCREMENT,
    `company_name` varchar(35)  NOT NULL,
    `company_industry` varchar(35)  NOT NULL,
    `company_location` varchar(50)  NOT NULL,
    PRIMARY KEY(`id`)
);
CREATE TABLE `People_Connections` (
    `id` INT AUTO_INCREMENT,
    `user_A` INT NOT NULL, -- Data type added
    `user_B` INT NOT NULL, -- Data type added
    PRIMARY KEY (`id`),
    FOREIGN KEY (`user_A`) REFERENCES `Users`(`id`),
    FOREIGN KEY (`user_B`) REFERENCES `Users`(`id`)
);

CREATE TABLE `School_Connection` (
    `id` INT AUTO_INCREMENT PRIMARY KEY,
    `school_id` INT NOT NULL,
    `student_id` INT NOT NULL,
    `start_date` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `end_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `degree_type` VARCHAR(35) NOT NULL,
    FOREIGN KEY (`school_id`) REFERENCES `Schools_and_Universities`(`id`),
    FOREIGN KEY (`student_id`) REFERENCES `Users`(`id`)
);


CREATE TABLE `Companies_Connection` (
    `id` INT AUTO_INCREMENT,
    `company_id` INT NOT NULL,
    `user_id` INT NOT NULL,
    `start_date` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    `end_date` TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `title` VARCHAR(35) NOT NULL,
    PRIMARY KEY (`id`),
    FOREIGN KEY (`company_id`) REFERENCES `Companies`(`id`),
    FOREIGN KEY (`user_id`) REFERENCES `Users`(`id`)
);



