<?php

/* hook_form_alter - tilføjer class til alle fields, således vi kan påføre en generel styling backend. */
function misc_modifications_form_alter(&$form, &$form_state, $form_id) {
	$indholdstyper = node_type_get_types();
	/* Vi kører en løkke der finder frem til alle machine names på indholdstyperne, og herefter laver vi en form alter. */
	foreach(element_children($indholdstyper) as $key) {
		if ($form_id == ($indholdstyper[$key]->type . '_node_form')) {	
			/* Tilføjer description til titel feltet */					
			$form['title']["#description"] = "Indholdets overskrift.";
			foreach(element_children($form) as $key) {
				$form[$key]['#attributes']['class'][] = 'general_field_styling';
			}
		}
	}
	/* Ændring af class på profil siden, samt tvinger metatag fieldset til at være åbent. */
	if ($form_id == 'user_profile_form') {
		foreach(element_children($form) as $key) {
				$form[$key]['#attributes']['class'][] = 'general_field_styling';
			}			
		$form['metatags']['#collapsible'] = FALSE;

	}
	/* Ved fil edit fjerner vi replace upload og redirect feltet. Fordi felterne virker overflødige */
	if ($form_id == 'file_entity_edit') {
		unset($form['replace_upload']);
		unset($form['redirect']);
	}
	/* Ændringer ved bean oprettelse/edit */
	if ($form_id == 'bean_form') {
		$form['label']['#description'] = "Etiketten vises kun i den administrative brugergrænseflade.";
		$form['title']['#required'] = TRUE;
		$form['title']['#description'] = 'Blokkens overskrift.';
		unset($form['redirect']);
		$form['field_billede']['#weight'] = 2;
		$form['field_bean_short_text']['#weight'] = 2;
		$form['field_bean_link']['#weight'] = 3;
		$form['field_bean_intern_link']['#weight'] = 3;
	}
}


?>