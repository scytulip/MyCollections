/* Convert all power wire label (net name) to net expression for inherited connections.
VDD!->[@power:%:VDD!], GND!->[@ground:%:GND!]
Based on the code from http://compgroups.net/comp.cad.cadence/replacing-label-text-with-skill/1352847 */

procedure( ReplaceLbl( libName viewName "tt" )
        let( ( d_libId d_cvId l_cellList l_labelList wireId lblPos lblPwr lblGnd)
		d_libId = ddGetObj(libName)
		l_cellList = setof(
              	d_cell d_libId~>cells
              	member( viewName d_cell~>views~>name ) 
			) ; Get all matched cellview in lib
		foreach( d_cell l_cellList
			d_cvId = dbOpenCellViewByType( libName d_cell~>name viewName nil "a" )
			l_labelList = setof( d_shape d_cvId~>shapes  d_shape~>objType == "label" )
			foreach( d_label l_labelList		; Check all labels in a cellview
				case( d_label~>theLabel
					( "VDD!"
						wireId = d_label~>parent ; Get attached net
						lblPos = d_label~>xy  ; Get position
						schDelete(d_label)    ; Delete the old label
						schCreateNetExpression(
							d_cvId "[@power:%:VDD!]" wireId lblPos
							"lowerLeft" "R0" "stick" 0.0625
							) ; Create a new net expression
					)
					( "GND!"
						wireId = d_label~>parent ; Get attached net
						lblPos = d_label~>xy  ; Get position
						schDelete(d_label)    ; Delete the old label
						schCreateNetExpression(
							d_cvId "[@ground:%:GND!]" wireId lblPos
							"lowerLeft" "R0" "stick" 0.0625
							) ; Create a new net expression
						
					)
				) ;; close case
			)

			schExtractConn(d_cvId)
			dbSave( d_cvId )
			dbClose( d_cvId )
		)
	)
)