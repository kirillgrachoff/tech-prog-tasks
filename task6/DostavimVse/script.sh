# ./mvnw -v
# ./mvnw package
# ./mvnw install
./mvnw spring-boot:run -P init-base
ls -la
./mvnw spring-boot:run -P web-app