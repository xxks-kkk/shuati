class DirectorySearchResult {
public:
  DirectorySearchResult( std::vector<std::string> const& files,
			 size_t attributes,
			 SearchQuery const* query )
    : files(files),
      attributes(attributes),
      query(new SearchQuery(*query))
  { }

  ~DirectorySearchResult() { delete query; }

private:
  std::vector<std::string> files;
  size_t attributes;
  SearchQuery* query;
};
