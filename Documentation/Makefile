all:
	mkdir -p generated
	pandoc -s -S --toc -f markdown_github -t html5 src/*.md -o generated/massive-docs.html
	pandoc -s -S --toc -f markdown_github -t epub src/*.md -o generated/massive-docs.epub
	pandoc -s -S --toc -f markdown_github -t markdown_github src/*.md -o generated/massive-docs.md
