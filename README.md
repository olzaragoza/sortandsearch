# sortandsearch
##### a simple C++ program that sorts and searches

- [![Gitter](http://img.shields.io/:chat-on_gitter-33CC99.svg)](https://gitter.im/olzaragoza/sortandsearch "Join the discussion")
- [Ways to Contribute](https://github.com/olzaragoza/sortandsearch/blob/master/CONTRIBUTING.md)

### [Issues](https://github.com/olzaragoza/sortandsearch/issues) [![Help](https://img.shields.io/badge/help-wanted-orange.svg)](https://github.com/olzaragoza/sortandsearch/issues)
- [value of selection sort exchanges incorrect](https://github.com/olzaragoza/sortandsearch/issues/1)

```c++
// selection sort on arrayTwo
void SortAndSearch::selectionSort()
{
	int startScan;
	int	minIndex;
	int	minValue;

	for (startScan = 0; startScan < (SIZE - 1); startScan++) {
		minIndex = startScan;
		minValue = arrayTwo[ startScan ];

		for (int i = startScan + 1; i < SIZE; i++) {
			if (arrayTwo[ i ] < minValue) {
				minValue = arrayTwo[ i ];
				minIndex = i;

				selectionCount++;	// count exchanges made
			}
		}

		arrayTwo[ minIndex ] = arrayTwo[ startScan ];
		arrayTwo[ startScan ] = minValue;
	}
}

```
