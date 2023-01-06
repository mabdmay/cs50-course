-- Keep a log of any SQL queries you execute as you solve the mystery.

-- crime scene reports on July 28, 2021
select description from crime_scene_reports where year = 2021 and day = 28 and month = 07;
-- The report says the crime took place at 10:15 and there were 3 witnesses whom interviews were conducted and
-- their transcripts are available in the interviews table

-- Reading transcripts of interviews conducted on 28 July, 2021
select transcript from interviews where year = 2021 and day = 28 and month = 07;
-- information obtained: 1. Within ten minutes of the theft, the thief got into a car in the bakery parking and drove away.
-- Check security footage from bakery parking lot for cars that left in 10 minutes of the theft
-- 2. The interviewee recognized the thief. He saw him at the Leggett Street ATM withdrawing some money
-- before the interviewee arrived at the Emma's bakery
-- 3. The theif called as he was leaving the bakery and talked to 2nd person for less than a minute saying that he is taking a flight out of fiftyville
-- tomorrow and asked the 2nd person to purchase flight tickets

-- Account numbers that made a bank withdrawal on 28 July 2021
select account_number from atm_transactions where year = 2021 and day = 28 and month = 07 and atm_location = "Leggett Street" and transaction_type = "withdraw";
-- 8 withdrawals took place

-- Names of people who made the withdrawal
select distinct(name) from people
join bank_accounts on bank_accounts.person_id = people.id
join atm_transactions on atm_transactions.account_number = bank_accounts.account_number
where bank_accounts.account_number in
(select account_number from atm_transactions
where year = 2021 and day = 28 and month = 07 and atm_location = "Leggett Street" and transaction_type = "withdraw");
-- 8 people: Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista

-- Cars which left within ten minutes of the theft
select license_plate from bakery_security_logs where year = 2021 and day = 28 and month = 07 and hour = 10 and minute > 15 and minute < 26 and activity = "exit";
-- 8 cars in total

-- Caller and Receiver info who made calls of less than 60s duration on 28 july 2021
select caller from phone_calls where year = 2021 and day = 28 and month = 07 and duration < 60;
-- 9 calls were made

-- flights id from fiftyville airport on 29 July 2021
select id, destination_airport_id, hour, minute from flights where origin_airport_id = 8 and day = 29 and month = 07 and year = 2021;
-- 5 flights

-- names of people who exited bakery parking on 28 july 2021 and made a call < 60s on 28 july 2021
select id, name from people
where phone_number in (
    select caller from phone_calls
    where year = 2021 and day = 28 and month = 07 and duration < 60
    )
and license_plate in (
    select license_plate from bakery_security_logs
    where year = 2021 and day = 28 and month = 07 and hour = 10 and minute > 15 and minute < 26 and activity = "exit"
    );
-- 4 names found: Sofia 398010, Diana 514354, Kelsey 560886, Bruce 686048 meaning one of these 4 is the theif

-- Names of people who exited bakery parking on 28 july 2021, made a <60s call and made a withdrawal from "Leggett Street" and took a flight
-- out of fiftyville on 29 july 2021
select id, name from people
join bank_accounts on bank_accounts.person_id = people.id
where people.phone_number in (
    select caller from phone_calls
    where year = 2021 and day = 28 and month = 07 and duration < 60
    )
and people.license_plate in (
    select license_plate from bakery_security_logs
    where year = 2021 and day = 28 and month = 07 and hour = 10 and minute > 15 and minute < 26 and activity = "exit"
    )
and bank_accounts.account_number in(
    select account_number from atm_transactions
    where year = 2021 and day = 28 and month = 07 and atm_location = "Leggett Street" and transaction_type = "withdraw"
)
and people.passport_number in(
    select passport_number from passengers
    where flight_id in (
        select id from flights
        where origin_airport_id = 8
        and day = 29 and month = 07
        and year = 2021
    )
);
-- 2 People: Bruce 686048 and Diana 514354

--Let's find out what cities did these 2 people went to
select airports.full_name, airports.id, airports.city from airports where airports.id in
(select flights.destination_airport_id from flights
    join airports on flights.origin_airport_id = airports.id
    join passengers on passengers.flight_id = flights.id
    join people on passengers.passport_number = people.passport_number
        where people.id in (514354, 686048)
        and flights.id in (
            select id from flights
            where origin_airport_id = 8 and day = 29
            and month = 07 and year = 2021));

-- One of them went to New York City and one of them went to Boston
-- Entering the two ids one at a time tells us that Diana went to Boston and Bruce went to NewYork City

-- Let's see who Bruce called and if he went to NewYork City as well
select name, id from people where phone_number = (
    select receiver from phone_calls
    where caller = (
        select phone_number from people where id = 686048
        )
        and year = 2021 and day = 28 and month = 07 and duration < 60
);
-- Bruce Called Robin therefore Robin is the accomplice and Bruce the theif who went to New York City