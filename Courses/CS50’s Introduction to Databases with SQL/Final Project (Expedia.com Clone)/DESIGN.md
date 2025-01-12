### Database Specification for Expedia.com Clone  

This database specification is designed to meet the requirements of a simplified Expedia.com clone as per the project guidelines. The focus is on creating a scalable, extensible, and normalized database structure that can be implemented by developers.

---

### **Functional Requirements Recap**

1. **Users**  
   - Two user types: Admin and Customer.  
   - Customers can manage itineraries.  

2. **Itineraries**  
   - A user can create multiple itineraries.  
   - Each itinerary includes flights and hotels (initial MVP).  
   - Extensible to include cars, activities, etc. in the future.  

3. **Flights**  
   - Each flight includes cost and user-selected details.  

4. **Hotels**  
   - Each hotel includes cost (calculated as total nights × price per night).  

5. **Itinerary Costs**  
   - The cost is the sum of all items in the itinerary.  

---

### **Database Schema**

#### **Tables and Relationships**

1. **Users Table**
   - **Purpose**: Store information about the application's users (both customers and admins).  
   - **Fields**:
     - `user_id` (Primary Key)
     - `username` (Unique, String)
     - `password` (Hashed, String)
     - `email` (Unique, String)
     - `user_type` (Enum: `Admin`, `Customer`)  

2. **Itineraries Table**
   - **Purpose**: Store information about each user's itinerary.  
   - **Fields**:
     - `itinerary_id` (Primary Key)
     - `user_id` (Foreign Key to `Users.user_id`)
     - `itinerary_name` (String, e.g., "Vacation to Hawaii")
     - `created_at` (Timestamp)
     - `total_cost` (Decimal, Auto-calculated)

3. **Flights Table**
   - **Purpose**: Store flight information for itinerary items.  
   - **Fields**:
     - `flight_id` (Primary Key)
     - `itinerary_id` (Foreign Key to `Itineraries.itinerary_id`)
     - `departure_city` (String)
     - `arrival_city` (String)
     - `departure_date` (Date)
     - `return_date` (Date, Nullable for one-way flights)
     - `cost` (Decimal)

4. **Hotels Table**
   - **Purpose**: Store hotel booking information for itinerary items.  
   - **Fields**:
     - `hotel_id` (Primary Key)
     - `itinerary_id` (Foreign Key to `Itineraries.itinerary_id`)
     - `hotel_name` (String)
     - `location` (String)
     - `check_in_date` (Date)
     - `check_out_date` (Date)
     - `price_per_night` (Decimal)
     - `total_nights` (Integer, Auto-calculated)
     - `cost` (Decimal, Auto-calculated as `total_nights × price_per_night`)

5. **Itinerary Items Table (Extensible)**
   - **Purpose**: To facilitate future extension of the application (e.g., cars, activities).  
   - **Fields**:
     - `item_id` (Primary Key)
     - `itinerary_id` (Foreign Key to `Itineraries.itinerary_id`)
     - `item_type` (Enum: `Flight`, `Hotel`, `Car`, etc.)
     - `item_reference_id` (Foreign Key to the respective table, e.g., `Flights.flight_id`, `Hotels.hotel_id`)
     - `cost` (Decimal, Auto-calculated from the referenced table)

---

### **Relationships**

1. **Users and Itineraries**:
   - One user can have multiple itineraries (`1-to-Many` relationship).  
   - `Users.user_id → Itineraries.user_id`  

2. **Itineraries and Flights**:
   - Each itinerary can have multiple flights (`1-to-Many` relationship).  
   - `Itineraries.itinerary_id → Flights.itinerary_id`  

3. **Itineraries and Hotels**:
   - Each itinerary can have multiple hotel bookings (`1-to-Many` relationship).  
   - `Itineraries.itinerary_id → Hotels.itinerary_id`  

4. **Itinerary Items**:
   - Acts as a polymorphic relationship to support future extensibility for other types of bookings.  

---

### **Key Calculations**

1. **Hotel Cost**:
   ```sql
   UPDATE Hotels
   SET total_nights = DATEDIFF(check_out_date, check_in_date),
       cost = total_nights * price_per_night;
   ```

2. **Itinerary Cost**:
   ```sql
   UPDATE Itineraries
   SET total_cost = (
       SELECT COALESCE(SUM(cost), 0)
       FROM (
           SELECT cost FROM Flights WHERE Flights.itinerary_id = Itineraries.itinerary_id
           UNION ALL
           SELECT cost FROM Hotels WHERE Hotels.itinerary_id = Itineraries.itinerary_id
       ) AS total_costs
   );
   ```

---

### **Sample Data**

#### Users
| user_id | username | password | email              | user_type |
|---------|----------|----------|--------------------|-----------|
| 1       | alice    | ****     | alice@example.com  | Customer  |
| 2       | admin1   | ****     | admin@example.com  | Admin     |

#### Itineraries
| itinerary_id | user_id | itinerary_name    | created_at      | total_cost |
|--------------|---------|-------------------|-----------------|------------|
| 1            | 1       | Hawaii Vacation   | 2025-01-01      | 1200.00    |

#### Flights
| flight_id | itinerary_id | departure_city | arrival_city | departure_date | cost  |
|-----------|--------------|----------------|--------------|----------------|-------|
| 1         | 1            | New York       | Honolulu     | 2025-02-01     | 600.00|

#### Hotels
| hotel_id | itinerary_id | hotel_name        | location      | check_in_date | check_out_date | price_per_night | total_nights | cost  |
|----------|--------------|-------------------|---------------|---------------|----------------|-----------------|--------------|-------|
| 1        | 1            | Waikiki Beach     | Honolulu      | 2025-02-01    | 2025-02-07     | 100.00          | 6            | 600.00|

---

This specification ensures that the project is robust, meets functional requirements, and is extensible for future needs. Let me know if you'd like further refinements or additional details!
