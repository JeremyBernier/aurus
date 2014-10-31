{
  "targets": [
    {
      "target_name": "hello",
      "sources": [ "hello.cc", 'engine.cc' ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      'link_settings': {
          'libraries': [
              '-ljack'
          ]
      }
    }
  ]
}
