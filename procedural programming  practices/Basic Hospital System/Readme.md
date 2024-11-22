
# Hospital System
## About:
My implementation to a simple Hospitals' classical systems.

## Main features of the Project:

1. **Multiple Specializations (20 in total)**:
   - The system supports 20 different medical specializations, each with its own queue for patients.

2. **Queue Management for Patients**:
   - Each specialization can have a queue of up to 5 patients.
   - Patients are added based on their status: either "regular" or "urgent."
     - **Regular patients** are added to the end of the queue.
     - **Urgent patients** are added to the front of the queue.
   - If a specialization’s queue is full, the system informs the patient that no more spots are available.

3. **Patient Information Storage**:
   - For each patient, the system stores their name, specialization, and urgency status.

4. **Doctor Interaction**:
   - When a doctor arrives, they specify the specialization, and the system selects the next patient in line for them.
   - If there are no patients in the queue for the requested specialization, the doctor is informed accordingly.

5. **Display of Patient Lists**:
   - The system can print a list of all patients waiting in each specialization, displaying their names and urgency status (regular or urgent).

6. **Error Handling**:
   - The system includes validation for incorrect user inputs such as out-of-range specialization numbers or invalid status values.
   - It also handles full queues and informs the patient when no further spots are available.
7. **Simple User Interface**:
   - The program presents a menu with options for adding new patients, printing the list of patients, handling doctor-patient interactions, and exiting the     
     system.
## Demo
[Demo.webm](https://github.com/user-attachments/assets/3271cceb-8c05-47b9-8e2b-64a3fb78b2f1)







