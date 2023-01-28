# GetNextLine tester

## Installation

- In your GetNextLine project folder :
```
git clone https://github.com/abdelbenamara/GetNextLine.git tests/
```

## Usage
```
make all
```
```
make bonus all
```

## Options

- Vanilla :
```
make norm test[-1|-42|-9999|-10M|-all] stdin[-1|-42|-9999|-10M|-all]
```
```
make norm test[-1|-42|-9999|-10M|-all] bonus stdin[-1|-42|-9999|-10M|-all]
```

- Valgrind :
```
make norm valgrind-test[-1|-42|-9999|-10M|-all] valgrind-stdin[-1|-42|-9999|-10M|-all]
```

```
make norm valgrind-test[-1|-42|-9999|-10M|-all] bonus valgrind-stdin[-1|-42|-9999|-10M|-all]
```

- Community :
```
make community-tests
```
