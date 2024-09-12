-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Here we check where the crime (the thieft) took place:
SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street' AND year = 2021 AND month = 7 AND day = 28;
-- Here we look at who was interviewed on 28/07/2021:
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
-- Here we look whom has the account that was used in the withdrawal of the money on Leggett Street on the day of the crime:
SELECT * FROM people WHERE licence_plate IN
(SELECT licence_plate FROM bakery_security_logs WHERE activity = 'exit' AND year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute = BETWEEN 15 AND 40)
AND phone_number IN (SELECT person_id FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
AND people.id IN (SELECT person-id FROM bank_accounts WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw'));
-- Here we check the phone number of the suspects and whom has the shorter phone call to narrow down the search:
SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller IN ("(286) 555-6063", "(770) 555-1861", "(367) 555-5533") AND receiver IN ("(676) 555-6554", "(725) 555-3243", "(375) 555-8161");
-- Here we can see who left Fiftyville the day after the crime:
SELECT * FROM flights JOIN airports on airports.id = flights.origin_airport_id WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.hour BETWEEN 00 AND 12 AND airports.city = 'Fiftyville' ORDER BY flights.hour, flights.minute;
-- Here we can see where those suspects went to determine who did the actual deed and where they fled:
SELECT full_name, city FROM airports WHERE id IN (1, 4, 11);
-- Here we check for certain suspects and where they went and if they came from Fiftyville:
SELECT name, passport_number FROM people WHERE people.name IN ('Bruce', 'Taylor', 'Diana', 'Philip', 'Robin', 'James') AND passport_number IN
(SELECT passport_number FROM passengers JOIN flights ON flights.id = passengers.flight_id JOIN airports ON airports.id = flights.origin_airport_id WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.hour BETWEEN 00 AND 12
AND flights.origin_airport_id IN (SELECT airports.id FROM airports WHERE airports.city = 'Fiftyville') AND flights.destination_airport_id IN (SELECT airports.id FROM airports WHERE airports.city IN 'New York', 'Chicago', 'San Fransisco'));
-- Here we can determine with more accuracy who the thief is and where they went:
SELECT full_name, city, passport_number, flights.destination_airport_id, flights.hour, flights.minute FROM airports JOIN flights ON flights.origin_airport_id = airport.id JOIN passengers ON passengers.flight_id = flights.id WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flight.hour BETWEEN 00 AND 12
AND passengers.passport_number IN (SELECT passport_number FROM people WHERE people.name IN ('Robin', 'Bruce', 'Diana', 'James', 'Taylor', 'Philip'));
-- We determined that Bruce and Robin did the crime and fled to New York City.
-- Thank goodness SQL is finished for now...
